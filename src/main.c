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
    inputState *input = initInput();
    Screen *base;
    BitMap c = {glyphs['*'], 8, 16};
    int i;

    base = screens[Primary];

    switchBuffer(Primary);

    drawBitMap(base, &c, 0, 0, SET);

    Vsync();

    while (1)
        ;

    switchBuffer(Original);

    deinitInput();
    return 0;
}
