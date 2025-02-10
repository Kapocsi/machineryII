#ifndef raster_h
#define raster_h

#include "bitmap.h"
#include "global.h"

/*
 * Defines the mode in which the bitmap should be drawn
 */
typedef enum { SET, UNSET } BitMapDrawMode;

/* Draw entire screen to black */
void black_screen(Screen *base);

/* Draw entire screen to white */
void white_screen(Screen *base);

/* Set Pixel at position to color - x,y = pixel coordinates
 * (must be in-bounds for the screen) */
void set_pixel(Screen *base, u16 x, u16 y, Color color);

/* Draw a bit map to the screen, the x,y offset being the top left corner of the
 * raster (must be in-bounds for the screen) */
void drawBitMap(Screen *base, BitMap *bitmap, u16 x_offset, u16 y_offset,
                BitMapDrawMode draw_mode);

/* x_pos,y_start,y_end = inclusive pixel coordinates (must be in-bounds for the
 * screen, y_start < y_end) */
void drawVerticalLine(Screen *base, u16 x_pos, u16 y_start, u16 y_end);

/* x_start,x_end,y_pos = inclusive pixel coordinates (must be in-bounds for the
 * screen, x_start < x_end) */
void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end);

#endif
