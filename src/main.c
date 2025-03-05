#include "font.h"
#include "global.h"
#include "raster.h"

#include "screen.h"
#include <assert.h>
#include <osbind.h>
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

int main(int argc, char *argv[]) {
    Screen **screens = initScreen();
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                 "Quisque elit est nulla";
    long ssp = 0;
    int i = 0;
    Screen *base;

    base = screens[Primary];
    white_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, SET);

    base = screens[Secondary];
    black_screen(base);
    for (i = 0; i < SCREEN_HEIGHT - 16; i += 16)
        drawSmallText(base, str, strlen(str), 0, i, UNSET);

    switchBuffer(Secondary);
    Crawcin();

    switchBuffer(Primary);

    Crawcin();

    switchBuffer(Original);

    return 0;
}
