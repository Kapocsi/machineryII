#include "bitmaps.h"
#include "global.h"
#include "input.h"
#include "raster.h"
#include "super.h"

#include "screen.h"
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
    Screen **screens = initScreen();
    inputState *is = initInput();
    Screen *base;
    int px, py, cx = 0, cy = 0;

    base = screens[Primary];
    switchBuffer(Primary);

    while (1) {
        px = cx;
        py = cy;

        cx = is->mouse.x;
        cy = is->mouse.y;

        drawBitMap8(base, &cursor, px, py, UNSET);
        drawBitMap8(base, &cursor, cx, cy, SET);

        Vsync();
    }

    deinitInput();
    switchBuffer(Original);

    return 0;
}
