#include <osbind.h>

#include "assert.h"
#include "global.h"
#include "screen.h"
#include "super.h"

#ifndef ST_LOW
typedef enum { ST_LOW = 0, ST_MED = 1, ST_HIGH = 2 } Resolutions;
#endif

/* Declared in switch.h */
void setBuffer(void *);

Screen alt_buffer[(bufferCount - 1) * SCREEN_BUFFER_SIZE + L_SB_ALIGN];
Screen *screens[bufferCount];

#define setIfNull(var, value) (var = var ? var : value)
#define alignTo(x, a) (void *)(((unsigned long)&x + (a - 1)) & ~(a - 1))

/** Contains the address of the logical base of the system */
#define lbase 0x00044E;

void switchBuffer(ScreenBuffer switch_to) {
    superIn();
    setBuffer(screens[switch_to]);
    superOut();
}

Screen **initScreen() {
    Screen *alt_buffer_start = alignTo(alt_buffer, L_SB_ALIGN);

    SuperDo(screens[Original] = *(Screen **)lbase);
    screens[Primary] = alt_buffer_start;
    screens[Secondary] = alt_buffer_start + SCREEN_BUFFER_SIZE;

    return screens;
}
