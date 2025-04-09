#include "raster.h"
#include "global.h"
#include <assert.h>
#include <stdio.h>

#define SWAP_VAL(X, Y)                                                         \
    X = Y ^ X;                                                                 \
    Y = X ^ Y;                                                                 \
    X = Y ^ X;

#define getOffset(x, y)                                                        \
    /* (x * 32) + (y * 20) */                                                  \
    (x >> 5) + (y << 4) + (y << 2)

static u32 min(u32 a, u32 b) {
    if (a > b)
        return b;
    return a;
}

static u32 max(u32 a, u32 b) {
    if (a > b)
        return a;
    else
        return b;
}

void black_screen(Screen *base) {
    register int i = 0;

    if (base == NULL)
        return;

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        base[i] = ~0L;
    }
}

void white_screen(Screen *base) {
    register int i = 0;

    if (base == NULL)
        return;

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        base[i] = 0;
    }
}

void set_pixel(Screen *base, u16 x, u16 y, Color color) {
    /*
     * TODO We can make this much faster if needed, most of this logic
     * is not needed if we use the bset operation that the m68k provides.
     */

    const u32 lmb = 0x0000000000000001;
    register u32 bitmap = lmb >> (x & 31);

    register u32 offset = getOffset(x, y);

    base[offset] = (base[offset] & ~bitmap) | (-color & bitmap);
}

/** I am so sorry...
 *
 * The code these function differs only in the types on a few lines of code, it
 * felt worse to do this as 3 functions with 90% repeated code
 *
 * All this does is create a function drawBitMap<N> that can operate on bitmaps
 * aligned or sized at n bits
 * **/
#define genDrawBitMap(size)                                                    \
    void drawBitMap##size(Screen *screen, const BitMap *bitmap,                \
                          const u16 x_start, const u16 y_start,                \
                          BitMapDrawMode draw_mode) {                          \
        u32 *baseEnd = (screen + SCREEN_BUFFER_SIZE);                          \
        u##size *base = (u##size *)screen;                                     \
        u##size *bmaps = (u##size *)bitmap->longs;                             \
        u##size x, y, xo, left, right;                                         \
                                                                               \
        xo = x_start % size;                                                   \
        base += y_start * (640l / size);                                       \
        base += x_start / size;                                                \
                                                                               \
        for (y = 0; y < bitmap->height; y++) {                                 \
            for (x = 0; x < bitmap->width / size; x++) {                       \
                if ((u32)base >= (u32)baseEnd)                                 \
                    return;                                                    \
                right = (*bmaps) << (size - xo);                               \
                left = (*bmaps++) >> xo;                                       \
                switch (draw_mode) {                                           \
                case (SET):                                                    \
                    *base++ |= left;                                           \
                    *base++ |= right;                                          \
                    break;                                                     \
                case (UNSET):                                                  \
                    *base++ &= ~left;                                          \
                    *base++ &= ~right;                                         \
                    break;                                                     \
                case (SWAP):                                                   \
                    *base++ ^= left;                                           \
                    *base++ ^= right;                                          \
                    break;                                                     \
                }                                                              \
                base--;                                                        \
            }                                                                  \
            base += (SCREEN_WIDTH / size) - (x);                               \
        }                                                                      \
    };

genDrawBitMap(8);
genDrawBitMap(16);
genDrawBitMap(32);

/* Interface of all draw bitmap functions */
typedef void (*drawBitMapFunc)(Screen *base, const BitMap *bitmap, u16 x_offset,
                               u16 y_offset, BitMapDrawMode draw_mode);

void drawBitMap(Screen *base, BitMap const *bitmap, const u16 x_start,
                const u16 y_start, BitMapDrawMode draw_mode) {
    /* v-table for finding the which bitmap draw version to call,
     * if bitmap is 32 aligned use the 32 aligned version, if 8 aligned
     * used that. etc.
     *
     * Table lookup function: (width % 32) / 8
     *  width % 32 allows us to check modulo {32,16,8} == 0 all at once
     *      if (x % 32 == {24,8}) then 8 | x.
     *      if (x % 32 == {16}) then 16 | x.
     *      if (x % 32 == 0) then 32 | x.
     *  collapsing the the output of the modulo 24 by the gcm (8) gives us
     *       8 | x -> 1,3
     *       16 | x -> 2
     *       32 | x -> 0
     *  hence the populated members of the vtable */
    drawBitMapFunc callTable[4] = {drawBitMap32, drawBitMap8, drawBitMap16,
                                   drawBitMap8};

    /* Allow for attempting to draw to null screen and drawing null bitmap,
    this might occur in debugging and we should handle it gracefully. */
    if (base == NULL || bitmap == NULL || bitmap->longs == NULL)
        return;

    /** We should only ever get values of 0,1,2, or 3. */
    assert(((bitmap->width & 31) >> 3) >= 0);
    assert(((bitmap->width & 31) >> 3) <= 3);

    callTable[(bitmap->width & 31) >> 3](base, bitmap, x_start, y_start,
                                         draw_mode);
}

void drawVerticalLine(Screen *base, u16 x, u16 y_start, u16 y_end) {

    /* offset to the current row */
    u16 y = (y_start << 4) + (y_start << 2);

    /* offset to the row containing the bottom of the line */
    u16 y_limit = (y_end << 4) + (y_end << 2);

    /* offset to the long on the screen containing the relevant pixel */
    u32 x_offset = x >> 5;

    /* LeftMost Bit (in a long) */
    u32 lmb = 1l << 31;
    /* a single bit placed where the line's pixel sits in the long */
    u32 bitmap = lmb >> (x & 31);

    for (; y <= y_limit; y += 20) {
        base[x_offset + y] |= bitmap;
    }
}

void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end,
                        BitMapDrawMode mode) {
    u32 mask;

    /* offset to the current long in the row */
    u8 x = x_start >> 5;
    /* offset to the long containing the end of the line */
    u8 x_limit = x_end >> 5;

    /* offset to the row containing the line */
    u16 y_offset = (y_pos << 4) + (y_pos << 2);

    /* offset (from the left) of the starting bit in the first long */
    u32 s_offset = x_start & 31;
    /* offset (from the left) of the ending bit in the last long */
    u32 e_offset = x_end & 31;

    if (mode == SET)
        mask = ~0l;
    else
        mask = 0l;

    if (x < x_limit) {
        /* fill in the first long */
        base[x + y_offset] |= mask >> s_offset;
        x++;

        /* fill in the intermediate longs */
        for (; x < x_limit; x++) {
            base[x + y_offset] = mask;
        }

        /* fill in the last long */
        base[x + y_offset] |= ~(mask >> e_offset);

    } else {
        base[x + y_offset] |= (mask >> s_offset) ^ (~0L >> e_offset);
    }
};
