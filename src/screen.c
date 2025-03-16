#include <osbind.h>
#include <stdio.h>

#include "assert.h"
#include "global.h"
#include "screen.h"

typedef enum { ST_LOW = 0, ST_MED = 1, ST_HIGH = 2 } Resolutions;

volatile Screen alt_buffer[(bufferCount - 1) * SCREEN_BUFFER_SIZE + L_SB_ALIGN];

Screen *screens[bufferCount];

#define setIfNull(var, value) (var = var ? var : value)
#define alignTo(x, a) (void *)(((unsigned long)&x + (a - 1)) & ~(a - 1))

void switchBuffer(ScreenBuffer switch_to) {
    static Screen *lbase;
    volatile long ssp = 0;
    setIfNull(lbase, Logbase());

    /** Ensure that buffer is properly aligned */
    assert((unsigned long)screens[switch_to] % 256 == 0);

    Super(0);
    Setscreen(lbase, screens[switch_to], ST_HIGH);
    Super(ssp);
    Vsync();
}

Screen **initScreen() {
    Screen *alt_buffer_start = alignTo(alt_buffer, L_SB_ALIGN);
    assert((long)alt_buffer_start % 256 == 0);

    setIfNull(screens[Original], Logbase());
    screens[Primary] = alt_buffer_start;
    screens[Secondary] = alt_buffer_start + (long)SCREEN_BUFFER_SIZE;

    return screens;
}
