#include "render.h"

#include "bitmaps.h"
#include "font.h"
#include "global.h"
#include "itoa.h"
#include "raster.h"
#include "screen.h"

static Model states[bufferCount];
static ScreenBuffer currentBuffer = Primary;

void draw(Screen *base, Model m, BitMapDrawMode mode) {
    char scoreBuffer[128] = "";

    itoa(m.score.score, scoreBuffer, 10);
    drawBitMap(base, &swimmer_idle_l, (SCREEN_WIDTH / 2) - 32, m.swimmer.y,
               mode);
    drawBigText(base, m.row.text, 0, SCREEN_HEIGHT - BIG_TEXT_HEIGHT - 1, mode);
    drawSmallText(base, scoreBuffer, 0, 0, mode);
}

void render(Model m, Screen **screens) {
    Screen *base = screens[(currentBuffer % 2) + 1];

    /* Remove the previous state */
    draw(base, states[currentBuffer], UNSET);
    /* Save current state for next undraw */
    states[currentBuffer] = m;
    draw(base, states[currentBuffer], SET);
};
