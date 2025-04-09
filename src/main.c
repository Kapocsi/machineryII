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
    u8 beat_count = 0;

    Screens screens = initScreen();
    Model model;

    srand(time(NULL)); /*this function must be called here (before start_game)
                         in order for the row text to be randomized.*/
    start_game(&model);
    change_row(&model.row, "Test Text");
    start_music();
    ticks = tickSinceInception();

    /*Main Game Loop*/
    while (model.swimmer.y < 3000) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();
        tick_increment(&model);

        if (beat_count >= 10) {
            update_music();
            beat_count = 0;
        } else {
            beat_count++;
        }
    }
    stop_sound();

    return 0;
}
