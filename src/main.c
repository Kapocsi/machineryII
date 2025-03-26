#include "global.h"
#include "input.h"
#include "model.h"
#include "events.h"
#include "render.h"
#include "screen.h"
#include "psg.h"
#include "music.h"

#include <assert.h>
#include <osbind.h>
#include <stdio.h>

/* Required Algorithm Structure in Main (Stage 5)

initialize model
render model (first frame)
start music
set quit = false

repeat until quit
    if input is pending
        process async event <-- update model requests
    if clock has ticked
        process sync events <-- update model data
        render model (next frame)
        update music
*/

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
    u8 prev_note = 0;

    Screens screens = initScreen();

    Model model = {{150}, {0}, {0}, {0}};

    printf("TODO!\n");


    start_game(&model);
    start_music();
    ticks = tickSinceInception();
    
    
    for (i = 0; i < 160; i++) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();
        tick_increment(&model);
        if (beat_count >= 20) {
            prev_note = update_music(prev_note);
            beat_count = 0;
        } else {
            beat_count++;
        }

    }
    stop_sound();

    return 0;
}
