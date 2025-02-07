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

void drawVerticalLine(Screen *base, u16 x, u16 y_start, u16 y_end) { TODO() }

void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end) {
    TODO()
};
