#include "screen.h"
#include "assert.h"
#include "global.h"
#include <osbind.h>
#include <stdio.h>

#define setIfNull(var, value) (var = var ? var : value)
#define alignTo(x, a) (void *)(((unsigned long)&x + (a - 1)) & ~(a - 1))

long alt_buffer[(bufferCount - 1) * SCREEN_BUFFER_SIZE + L_SB_ALIGN];
Screen *screens[bufferCount];

void switchBuffer(ScreenBuffer switch_to) {
    static Screen *lbase;
    long ssp = 0;
    setIfNull(lbase, Logbase());

    /** Ensure that buffer is properly aligned */
    assert((unsigned long)screens[switch_to] % 256 == 0);

    Super(0);
    Setscreen(lbase, screens[switch_to], ST_HIGH);
    Super(ssp);
    Vsync();
}

void deinitScreen() {
    switchBuffer(Original);
    printf("done deinit \n");
}

Screen **initScreen() {
    Screen *alt_buffer_start = alignTo(alt_buffer, L_SB_ALIGN);
    assert((long)alt_buffer_start % 256 == 0);

    setIfNull(screens[0], Logbase());
    screens[1] = alt_buffer_start;

    screens[2] = alt_buffer_start + (long)SCREEN_BUFFER_SIZE;

    return screens;
}
