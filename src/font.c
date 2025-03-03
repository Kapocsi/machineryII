#include "font.h"
#include "global.h"
#include "raster.h"
#include <assert.h>

#define SMALL_TEXT_WIDTH 8
#define SMALL_TEXT_HEIGHT 16
#define BIG_TEXT_WIDTH 64
#define BIG_TEXT_SPACING 48
#define BIG_TEXT_HEIGHT 65

void drawSmallText(Screen *base, char *str, u32 text_len, u16 x, u16 y,
                   BitMapDrawMode drawMode) {
    BitMap c = {0, SMALL_TEXT_WIDTH, SMALL_TEXT_HEIGHT};
    u16 i = 0;

    /* Assert in bounds */
    assert(SMALL_TEXT_WIDTH * text_len + x < SCREEN_WIDTH);
    assert(y + SMALL_TEXT_HEIGHT < SCREEN_HEIGHT);

    for (i = 0; i < text_len; i++) {
        /** Load the correct gyph into the bitmap struct */
        c.longs = glyphs[str[i]];

        drawBitMap(base, &c, x + i * SMALL_TEXT_WIDTH, y, drawMode);
    }
}

void drawBigText(Screen *base, char *str, u32 text_len, u16 x, u16 y,
                 BitMapDrawMode drawMode) {
    u16 i = 0;

    assert(BIG_TEXT_SPACING * text_len + x < SCREEN_WIDTH);
    assert(y + BIG_TEXT_HEIGHT < SCREEN_HEIGHT);

    for (i = 0; i < text_len; i++) {
        drawBitMap(base, &depixel[str[i]], x + BIG_TEXT_SPACING * i, y,
                   drawMode);
    }
}
