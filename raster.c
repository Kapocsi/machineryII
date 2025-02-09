#include "raster.h"
#include "global.h"
#include <stdio.h>

void black_screen(Screen *base) {
    register int i = 0;

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        base[i] = ~0L;
    }
}

void white_screen(Screen *base) {
    register int i = 0;

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        base[i] = 0;
    }
}

void set_pixel(Screen *base, u16 x, u16 y, Color color) {
    /*
     * TODO We can make this much faster if needed, most of this logic
     * is not needed if we use the bset operation that the m68k provides.
     */

    /* 0b10....0 */
    const u32 lmb = 1 << 31;
    /* Set n-th in long to high */
    register u32 bitmap = lmb >> (x & 31);
    /* Offset to the long on the screen containing the relevant pixel */
    register u32 offset = (x >> 5) + (y << 4) + (y << 2);

    base[offset] = (base[offset] & ~bitmap) | (-color & bitmap);
}

void drawBitMap(Screen *base, BitMap *bitmap, u16 x, u16 y,
                BitMapDrawMode draw_mode) {
    TODO();
}

void drawVerticalLine(Screen *base, u16 x, u16 y_start, u16 y_end) { 

    /* offset to the current row */
    u16 y = (y_start << 4) + (y_start << 2);

    /* offset to the row containing the bottom of the line */
    u16 y_limit = (y_end << 4) + (y_end << 2);

    /* offset to the long on the screen containing the relevant pixel */
    u32 x_offset = x >> 5;
    
    /* a single bit placed where the line's pixel sits in the long */
    u32 bitmap = 1 << (31 - (x & 31));

    for (; y <= y_limit; y += 20) {
        base[x_offset + y] |= bitmap;
    }    
}

void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end) {

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
    
    if (x < x_limit) {
        /* fill in the first long */
        base[x + y_offset] |= ~0L >> s_offset;
        x++;

        /* fill in the intermediate longs */
        for (; x < x_limit; x++) {
            base[x + y_offset] = ~0L;
        }

        /* fill in the last long */
        base[x + y_offset] |= ~(~0L >> e_offset);

    } else {
        base[x + y_offset] |= (~0L >> s_offset) ^ (~0L >> e_offset);
    }

};
