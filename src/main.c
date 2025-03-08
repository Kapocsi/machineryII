#include "font.h"
#include "global.h"
#include "input.h"
#include "raster.h"

#include "screen.h"
#include <assert.h>
#include <osbind.h>
#include <stdio.h>

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
    BitMap c = {glyphs['*'], 8, 16};
    Screen *base = screens[Original];
    int first = 1;
    int cx, cy;
    int px = 0, py = 0;
    initInput();

    while (1) {
        base = nextBuffer();

        cx = (((x + SCREEN_WIDTH) % SCREEN_WIDTH) / 8) * 8;
        cy = (y + SCREEN_HEIGHT) % SCREEN_HEIGHT;

        drawBitMap(base, &c, px, py, UNSET);
        drawBitMap(base, &c, cx, cy, SET);

        px = cx;
        py = cy;
    }

    deinitInput();
    return 0;
}
