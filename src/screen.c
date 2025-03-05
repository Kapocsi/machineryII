#include "screen.h"
#include "assert.h"
#include "global.h"

#define setIfNull(var, value) (var = var ? var : value)
#define alignTo(x, a) (void *)(((unsigned long)&x + (a - 1)) & ~(a - 1))

long alt_buffer[(bufferCount - 1) * SCREEN_BUFFER_SIZE + L_SB_ALIGN];
Screen *screens[bufferCount];

void switchBuffer(ScreenBuffer switch_to) {
    static Screen *physBase;
    long ssp = 0;
    setIfNull(physBase, Physbase());

    Super(0);
    Setscreen(screens[switch_to], physBase, ST_HIGH);
    Super(ssp);
}

void deinitScreen() { switchBuffer(Original); }

Screen **initScreen() {
    Screen *alt_buffer_start = alignTo(alt_buffer, L_SB_ALIGN);

    setIfNull(screens[0], Logbase());
    screens[0] = alt_buffer_start;
    screens[1] = alt_buffer_start + SCREEN_BUFFER_SIZE;

    return screens;
}
