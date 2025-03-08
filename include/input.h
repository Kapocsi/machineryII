#ifndef INPUT_H
#define INPUT_H

#include "osbind.h"

typedef void (*Vector)();

void initInput();
void deinitInput();

extern int x, y;

#endif
