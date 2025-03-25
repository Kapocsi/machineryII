/**
 * @file font.h
 * @brief Header file for font rendering functions.
 *
 * This file contains declarations for rendering text on a screen.
 * It defines glyph data structures and functions for drawing
 * both small and large text.
 */

#ifndef FONT_H
#define FONT_H

#define SMALL_TEXT_WIDTH 8
#define SMALL_TEXT_HEIGHT 16
#define BIG_TEXT_WIDTH 64
#define BIG_TEXT_SPACING 48
#define BIG_TEXT_HEIGHT 65

#include "global.h"
#include "raster.h"

/**
 * @brief Glyph data for ASCII characters 0-127.
 *
 * This array stores 4x32-bit values per character, representing bitmap data
 * for rendering small font glyphs.
 */
extern const u32 glyphs[128][4];

/**
 * @brief Predefined bitmap representations of glyphs.
 *
 * This array contains bitmap structures for rendering font characters
 * in a larger size.
 */
extern const BitMap depixel[];

/**
 * @brief Renders small-sized text on the screen.
 *
 * @param base Pointer to the screen buffer.
 * @param str The null-terminated string to be drawn.
 * @param x X-coordinate of the text position.
 * @param y Y-coordinate of the text position.
 * @param drawMode Drawing mode to be applied.
 */
void drawSmallText(Screen *base, char *str, u16 x, u16 y,
                   BitMapDrawMode drawMode);

/**
 * @brief Renders large-sized text on the screen.
 *
 * @param base Pointer to the screen buffer.
 * @param str The null-terminated string to be drawn.
 * @param x X-coordinate of the text position.
 * @param y Y-coordinate of the text position.
 * @param drawMode Drawing mode to be applied.
 */
void drawBigText(Screen *base, char *str, u16 x, u16 y,
                 BitMapDrawMode drawMode);

/**
 * @brief Draw a underline under a character when draw at the bottom of the
 * screen
 *
 * @param base Pointer to the screen buffer.
 * @param pos index of the char to underline
 */
void drawBigTextUnderline(Screen *base, u8 pos);

#endif
