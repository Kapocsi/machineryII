#ifndef raster_h
#define raster_h

#include "global.h"

typedef struct {
    u8 *bytes;
    u8 width;
    u8 height;
} BitMap;

/*
 * Defines the mode in which the bitmap should be drawn
 */
typedef enum { SET, UNSET } BitMapDrawMode;

/* Draw entire screen to black */
void black_screen(Screen *base);

/* Draw entire screen to white */
void white_screen(Screen *base);

/* Set Pixel at position to color */
void set_pixel(Screen *base, u16 x, u16 y, enum Color color);

/* Draw a bit map to the screen, the x,y offset being the top left corner of the
 * raster */
void drawBitMap(Screen *base, BitMap *bitmap, u8 x_offset, u8 y_offset,
                BitMapDrawMode draw_mode);

/* Draw a line, centered at a point at some angle theta (in degreess) */
void drawLine(Screen *base, u8 angle, u8 x, u8 y);

#endif
