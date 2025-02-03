#ifndef raster_h
#define raster_h

#include "global.h"

void blank_screen(Screen *base);
void white_screen(Screen *base);

void set_pixel(Screen *base, int x, int y, Color color);

#endif
