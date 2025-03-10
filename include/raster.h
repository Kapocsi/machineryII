/**
 * @file raster.h
 * @brief Provides functions for raster graphics operations.
 *
 * This header defines functions for manipulating a screen buffer,
 * including pixel drawing, line drawing, and bitmap rendering.
 */

#ifndef RASTER_H
#define RASTER_H

#include "global.h"

/**
 * @enum BitMapDrawMode
 * @brief Specifies the mode in which a bitmap should be drawn.
 *
 * This enumeration determines whether the bitmap pixels should be set
 * (drawn as active) or unset (removed from the screen).
 */
typedef enum {
    SET,  /**< Set pixels in the bitmap (turn them on). */
    UNSET /**< Unset pixels in the bitmap (turn them off). */
} BitMapDrawMode;

/**
 * @brief Clears the entire screen by filling it with black.
 *
 * @param base Pointer to the screen buffer.
 */
void black_screen(Screen *base);

/**
 * @brief Clears the entire screen by filling it with white.
 *
 * @param base Pointer to the screen buffer.
 */
void white_screen(Screen *base);

/**
 * @brief Sets a pixel at the specified coordinates to a given color.
 *
 * @param base Pointer to the screen buffer.
 * @param x X-coordinate of the pixel (must be in-bounds & multiple of 8).
 * @param y Y-coordinate of the pixel (must be in-bounds & multiple of 8).
 * @param color The color to set the pixel to.
 */
void set_pixel(Screen *base, u16 x, u16 y, Color color);

/**
 * @brief Draws a bitmap onto the screen at the specified coordinates.
 *
 *
 *
 * @param base Pointer to the screen buffer.
 * @param bitmap Pointer to the bitmap to be drawn.
 * @param x_offset X-coordinate of the top-left corner of the bitmap (must be
 * in-bounds).
 * @param y_offset Y-coordinate of the top-left corner of the bitmap (must be
 * in-bounds).
 * @param draw_mode The drawing mode (SET or UNSET).
 */
void drawBitMap(Screen *base, const BitMap *bitmap, u16 x_offset, u16 y_offset,
                BitMapDrawMode draw_mode);

/**
 * @brief Draws a vertical line on the screen.
 *
 * @param base Pointer to the screen buffer.
 * @param x_pos X-coordinate of the line (must be in-bounds).
 * @param y_start Starting Y-coordinate (must be in-bounds, y_start < y_end).
 * @param y_end Ending Y-coordinate (must be in-bounds).
 */
void drawVerticalLine(Screen *base, u16 x_pos, u16 y_start, u16 y_end);

/**
 * @brief Draws a horizontal line on the screen.
 *
 * @param base Pointer to the screen buffer.
 * @param y_pos Y-coordinate of the line (must be in-bounds).
 * @param x_start Starting X-coordinate (must be in-bounds, x_start < x_end).
 * @param x_end Ending X-coordinate (must be in-bounds).
 */
void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end);

void drawBitMap8(Screen *screen, const BitMap *bitmap, const u16 x_start,
                 const u16 y_start, BitMapDrawMode draw_mode);

#endif /* RASTER_H */
