/**
 * @file bitmap.h
 * @brief Defines the BitMap struct.
 *
 * This file contains only the definition of the BitMap struct. It exists
 * to prevent circular dependencies between raster.h and bitmaps.h,
 * which both require this struct and each other.
 */

#ifndef BITMAP_H
#define BITMAP_H

#include "global.h"

/**
 * @struct BitMap
 * @brief Represents a bitmap image using a pointer to pixel data and its
 * dimensions.
 *
 * The BitMap struct stores a reference to an array of 32-bit unsigned integers
 * representing the bitmap's pixel data, along with its width and height.
 */
typedef struct {
    const u32 *longs; /**< Pointer to an array of 32-bit unsigned integers
                         representing pixel data. */
    const u8 width;   /**< Width of the bitmap in pixels. */
    const u8 height;  /**< Height of the bitmap in pixels. */
} BitMap;

#endif /* BITMAP_H */
