#include "bitmaps.h"
#include "raster.h"
#include <assert.h>

static const u32 _bb[32] = {
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
};
const BitMap BlackBox = {_bb, 32, 32};
