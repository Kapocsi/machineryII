#ifndef SCREEN_H
#define SCREEN_H

#include "global.h"

typedef enum { Original, Primary, Secondary } ScreenBuffer;

#define bufferCount 3

/**
 * @brief
 *
 * @param switch_to
 */
void switchBuffer(ScreenBuffer switch_to);
Screen **initScreen();
void deinitScreen();
Screen *nextBuffer();

extern Screen *screens[bufferCount];

#endif
