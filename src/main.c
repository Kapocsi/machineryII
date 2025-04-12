#include "events.h"
#include "global.h"
#include "input.h"
#include "model.h"
#include "music.h"
#include "psg.h"
#include "render.h"
#include "screen.h"
#include "vbl.h"
#include "vector.h"

#include <assert.h>
#include <osbind.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef Screen **Screens;

int main(int argc, char *argv[]) {

    int i = 0;
    u32 ticks;
    u32 oticks;

    Screens screens = initScreen();
    inputState *input_state = initInput();
    Model model;

    srand(time(NULL)); /*this function must be called here (before start_game)
                         in order for the row text to be randomized.*/
    start_game(&model);
    change_row(&model.row, "Test Text");
    start_music();
    ticks = tickSinceInception();
    oticks = ticks;

    /*Main Game Loop*/
    while (model.swimmer.y < 70) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();
        tick_increment(&model);

        render(model, screens);
        update_music();
    }
    printf("Outside game loop\n");
    deinitInput();
    stop_sound();

    return 0;
}
