#include "render.h"

#include "bitmaps.h"
#include "font.h"
#include "global.h"
#include "itoa.h"
#include "raster.h"
#include "screen.h"
#include <osbind.h>
#include <string.h>

static Model states[bufferCount - 1];
static Model om;
static u8 buf_idx = Primary;
static char scoreBuffer[32] = "";

#define changed(val) (m.val != om.val)

void draw(Screen *base, Model m, BitMapDrawMode mode) {
    drawBigText(base, m.row.text, 0, SCREEN_HEIGHT - BIG_TEXT_HEIGHT - 1, mode);
}

void render(Model m, Screen **screens) {
    register Screen *base;

    buf_idx = ((buf_idx + 1) & 1);
    base = screens[buf_idx + 1];
    om = states[buf_idx];

    if changed (score.score) {
        itoa(om.score.score, scoreBuffer, 10);
        drawSmallText(base, scoreBuffer, 0, 0, UNSET);

        itoa(m.score.score, scoreBuffer, 10);
        drawSmallText(base, scoreBuffer, 0, 0, SET);
    }

    if changed (swimmer.y) {
        drawBitMap(base, &swimmer_idle_l, (SCREEN_WIDTH / 2) - 32, om.swimmer.y,
                   UNSET);
        drawBitMap(base, &swimmer_idle_l, (SCREEN_WIDTH / 2) - 32, m.swimmer.y,
                   SET);
    }

    if (strcmp(om.row.text, m.row.text) != 0) {
        drawBigText(base, om.row.text, 0, SCREEN_HEIGHT - BIG_TEXT_HEIGHT - 1,
                    UNSET);
        drawBigText(base, m.row.text, 0, SCREEN_HEIGHT - BIG_TEXT_HEIGHT - 1,
                    SET);
    }

    /* Save current state for next undraw */
    states[buf_idx] = m;
    switchBuffer(buf_idx + 1);

    Vsync();
};
