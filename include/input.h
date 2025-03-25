#ifndef INPUT_H
#define INPUT_H

#include "global.h"
typedef void (*Vector)();

typedef struct {
    int x;
    int y;
} Mouse;

typedef volatile struct {
    Mouse mouse;
    enum Bool capsLock;
    enum Bool shift;

} inputState;

inputState *initInput();
void deinitInput();

#endif
