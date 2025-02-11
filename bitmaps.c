#include "bitmaps.h"
#include "raster.h"
#include <assert.h>

static const u32 _bb[32] = {
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
    ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l, ~0l,
};
const BitMap BlackBox = {_bb, 32, 32};

u32 array[] = {
    0x0,        0x0,        0x0,       0x0,        0x0,       0x80000000,
    0x3fffffff, 0xfffffff8, 0x0,       0x80000000, 0x0,       0x80000000,
    0x0,        0x80000000, 0x0,       0x80000000, 0x0,       0x80000000,
    0x0,        0x80000000, 0x1e00000, 0x80000f00, 0x2100000, 0x80001080,
    0x4080003,  0xf0002040, 0x8040004, 0x88004020, 0x8040008, 0x84004020,
    0x8040010,  0x82004020, 0x8040010, 0x82004020, 0x8040010, 0x82004020,
    0x4080010,  0x82004020, 0x2100008, 0x84002040, 0x1e00004, 0x88001080,
    0x3,        0xf0000f00, 0x0,       0x80000000, 0x0,       0x80000000,
    0x0,        0x80000000, 0x0,       0x80000000, 0x0,       0x80000000,
    0x3fffffff, 0xfffffffc, 0x0,       0x0,        0x0,       0x0,
    0x0,        0x0,        0x0,       0x0};

const BitMap test = {array, 64, 32};
