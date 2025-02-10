/*
 * This file only contains the deintion of the BitMap Struct we do this since
 * both raster.h and bitmaps.h need this and each other and thus would cause a
 * circular include. Hence we need this atrocity
 *
 */

#ifndef BITMAP_H
#define BITMAP_H

#include "global.h"

typedef struct {
    const u32 *longs;
    const u8 width;
    const u8 height;
} BitMap;

#endif
