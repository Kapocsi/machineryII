#ifndef INPUT_H
#define INPUT_H

typedef void (*Vector)();

typedef struct {
    int x;
    int y;
} Mouse;

typedef volatile struct {
    Mouse mouse;
} inputState;

inputState *initInput();
void deinitInput();

#endif
