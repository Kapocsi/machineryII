#include "bitmaps.h"
#include "font.h"
#include "global.h"
#include "raster.h"
#include "screen.h"
#include "super.h"

#include <assert.h>
#include <osbind.h>

void disable_cursor() {
    printf("\033f");
    fflush(stdout);
}

void enable_cursor() {
    printf("\033e");
    fflush(stdout);
}

u32 tickSinceInception() {
    u32 ticks;
    SuperDo(ticks = *(u32 *)(0x462));
    return ticks;
}

void setBuffer(void *);

int main(int argc, char *argv[]) {
    int x, i = 0;
    Screen **screens = initScreen();
    Screen *base = screens[Original];
    white_screen(base);

    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern8, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern8, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern16, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern16, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern32, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern32, x, 0, UNSET);
    }
    for (x = 0; x < 64; x++) {
        drawBitMap(base, &test_pattern64, x, 0, SET);
        Cconin();
        drawBitMap(base, &test_pattern64, x, 0, UNSET);
    }

    return 0;
}
