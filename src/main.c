#include "font.h"
#include "global.h"
#include "raster.h"

#include "screen.h"
#include <assert.h>
#include <osbind.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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

    base = screens[Original];

    white_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, SET);

    black_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, UNSET);

    /* switchBuffer(Primary); */
    /**/
    /* Cconin(); */
    /* switchBuffer(Original); */

    return 0;
}
