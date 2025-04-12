#include "bitmaps.h"
#include "events.h"
#include "font.h"
#include "global.h"
#include "input.h"
#include "model.h"
#include "music.h"
#include "psg.h"
#include "raster.h"
#include "render.h"
#include "screen.h"
#include "words.h"

#include <assert.h>
#include <osbind.h>
#include <stdio.h>
#include "string.h"

void disable_cursor() {
    printf("\033f");
    fflush(stdout);
}

void enable_cursor() {
    printf("\033e");
    fflush(stdout);
}

u32 tickSinceInception() {
    long ssp = Super(0);
    u32 ticks = *(u32 *)(0x462);
    Super(ssp);

    return ticks;
}

typedef struct {
    Screen *buf;
    Mouse mouse;
} State;

typedef Screen **Screens;

int main(int argc, char *argv[]) {

    int i = 0;
    u32 ticks;
    u32 oticks;

    Screens screens = initScreen();
    inputState *input_state = initInput();
    Model model;


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
    ticks = tickSinceInception();

    while (tickSinceInception() - ticks < 300) {
        state = &states[state_index];
        state_index = (state_index + 1) % 2;

        drawBitMap(state->buf, &cursor, state->mouse.x, state->mouse.y, SWAP);
        state->mouse = input_state->mouse;
        drawBitMap(state->buf, &cursor, state->mouse.x, state->mouse.y, SWAP);

        switchBuffer(state_index + 1);

        Vsync();
    }
    white_screen(screens[Original]);
    white_screen(screens[Primary]);
    white_screen(screens[Secondary]);


    screens = initScreen();
    start_game(&model);
    new_row(model.row.text, 25);
    start_music();
    ticks = tickSinceInception();
    oticks = ticks;

    /*Main Game Loop*/
    while (model.swimmer.y <= 200) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();
        tick_increment(&model);

        render(model, screens);

        if (tickSinceInception() - oticks > 6) {
            update_music();

            oticks = tickSinceInception();
        }
    }

    death();
    strcpy(model.row.text, "You died");
    render(model, screens);
    ticks = tickSinceInception();
    while (tickSinceInception() - ticks < 100)
        ;

    stop_sound();
    deinitInput();
    switchBuffer(Original);

    return 0;
}
