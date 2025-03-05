#ifndef SCREEN_H
#define SCREEN_H

#include "global.h"

typedef enum { Original, Primary, Secondary } ScreenBuffer;
typedef enum { ST_LOW = 0, ST_MED = 1, ST_HIGH = 2 } Resolutions;

#define bufferCount 3

void switchBuffer(ScreenBuffer switch_to);
Screen **initScreen();
void deinitScreen();
extern Screen *screens[bufferCount];

#endif
