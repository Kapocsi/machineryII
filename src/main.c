#include "font.h"
#include "global.h"
#include "music.h"
#include "psg.h"
#include "raster.h"
#include "events.h"

#include "screen.h"
#include <assert.h>
#include <osbind.h>
#include <stdio.h>
#include <string.h>

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

int main(int argc, char *argv[]) {
    Screen **screens = initScreen();
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                 "Quisque elit est null\n";
    long ssp = 0;
    int i = 0;
    Screen *base;
    u32 start = 0;
    u32 ticks;
    u8 beat_count = 0;
    u8 prev_note = 0;

    Model model = {{150}, {0}, {0}, {0}};

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

    base = screens[Primary];
    white_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, SET);

    base = screens[Secondary];
    black_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, UNSET);

    switchBuffer(Primary);
    Cconin();
    switchBuffer(Secondary);
    Cconin();
    switchBuffer(Original);

    return 0;
}
