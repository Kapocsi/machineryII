#include <osbind.h>
#include <stdio.h>

#include "assert.h"
#include "global.h"
#include "screen.h"

typedef enum { ST_LOW = 0, ST_MED = 1, ST_HIGH = 2 } Resolutions;

volatile Screen alt_buffer[(bufferCount - 1) * SCREEN_BUFFER_SIZE + L_SB_ALIGN];

static Screen *screens[bufferCount];

#define setIfNull(var, value) (var = var ? var : value)
#define alignTo(x, a) (void *)(((unsigned long)&x + (a - 1)) & ~(a - 1))

void switchBuffer(ScreenBuffer switch_to) {
    Screen *pbase = Physbase();
    volatile long ssp = 0;

    Super(0);
    Setscreen(screens[switch_to], pbase, ST_HIGH);
    Vsync();
    Super(ssp);
}

Screen **initScreen() {
    long ssp = 0;
    Screen *alt_buffer_start = alignTo(alt_buffer, L_SB_ALIGN);
    int i;

    screens[Original] = Logbase();
    screens[Primary] = alt_buffer_start;
    screens[Secondary] = alt_buffer_start + SCREEN_BUFFER_SIZE;

    for (i = 0; i <= Secondary; i++)
        printf("%lx\t", (u32)screens[i]);
    printf("\n");

    return screens;
}
