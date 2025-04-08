#include "bitmaps.h"
#include "font.h"
#include "global.h"
#include "input.h"
#include "raster.h"
#include "screen.h"
#include <osbind.h>

typedef struct {
    Screen *buf;
    Mouse mouse;
} State;

int main() {
    Screen **screens = initScreen();
    inputState *inputState = initInput();
    Screen *base = screens[Primary];
    int state_index = 0;
    State states[2];
    State *state;

    states[0].buf = screens[Primary];
    states[1].buf = screens[Secondary];

    drawBigText(states[0].buf, "Man Over", 20, 0, SET);
    drawBigText(states[0].buf, "Board", 20, 65, SET);

    drawBigText(states[1].buf, "Man Over", 20, 0, SET);
    drawBigText(states[1].buf, "Board", 20, 65, SET);

    drawSmallText(states[0].buf, "Single Player", 200, 200, SET);
    drawSmallText(states[0].buf, "Quit", 200, 220, SET);

    drawSmallText(states[1].buf, "Single Player", 200, 200, SET);
    drawSmallText(states[1].buf, "Quit", 200, 220, SET);

    Vsync();

    while (1) {
        state = &states[state_index];
        state_index = (state_index + 1) % 2;

        drawBitMap(state->buf, &cursor, state->mouse.x, state->mouse.y, SWAP);
        state->mouse = inputState->mouse;
        drawBitMap(state->buf, &cursor, state->mouse.x, state->mouse.y, SWAP);

        switchBuffer(state_index + 1);

        Vsync();
    }

    deinitInput();
}
