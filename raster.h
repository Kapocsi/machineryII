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
void set_pixel(Screen *base, u16 x, u16 y, Color color);

/* Draw a bit map to the screen, the x,y offset being the top left corner of the
 * raster */
void drawBitMap(Screen *base, BitMap *bitmap, u16 x_offset, u16 y_offset,
                BitMapDrawMode draw_mode);

void drawVerticalLine(Screen *base, u16 x_pos, u16 y_start, u16 y_end);

void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end);

#endif
