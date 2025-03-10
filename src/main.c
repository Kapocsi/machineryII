#include <assert.h>
#include <osbind.h>
#include <stdio.h>

#include "bitmaps.h"
#include "global.h"
#include "raster.h"
#include "screen.h"
#include "super.h"

u32 tickSinceInception() {
    u32 ticks;
    SuperDo(ticks = *(u32 *)(0x462));
    return ticks;
}

void setBuffer(void *);

int main(int argc, char *argv[]) {
    Screen **screens = initScreen();
    /* inputState *is = initInput(); */
    Screen *base;
    int px, py, cx = 0, cy = 0;

    base = screens[Original];
    /* switchBuffer(Primary); */
    white_screen(base);

    for (px = 0; px < 8; px++) {
        drawBitMap8(base, &cursor, px, 0, SET);
        Cconin();
        drawBitMap8(base, &cursor, px, 0, UNSET);
    }

    /* deinitInput(); */
    switchBuffer(Original);

    return 0;
}
