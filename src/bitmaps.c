#include "bitmaps.h"

static const u32 _cursor[2] = {0xf0c0a090, 0x8040201};

const BitMap cursor = {_cursor, 8, 8};
;

static const u32 _test_pattern16[8] = {0x80014002, 0x200413c8, 0xc300c30,
                                       0x12481188, 0x11881248, 0xc300c30,
                                       0x13c82004, 0x40028001};

const BitMap test_pattern16 = {_test_pattern16, 16, 16};
;

static const u32 _test_pattern32[32] = {
    0x80000001, 0x40000002, 0x20000004, 0x10000008, 0x8000010,  0x4000020,
    0x2000040,  0x1000080,  0x800100,   0x43c200,   0x2c3400,   0x100800,
    0x281400,   0x242400,   0x424200,   0x418200,   0x418200,   0x424200,
    0x242400,   0x281400,   0x100800,   0x2c3400,   0x43c200,   0x800100,
    0x1000080,  0x2000040,  0x4000020,  0x8000010,  0x10000008, 0x20000004,
    0x40000002, 0x80000001};

const BitMap test_pattern32 = {_test_pattern32, 32, 32};
;

static const u32 _test_pattern64[128] = {
    0x80000000, 0x1,        0x40000000, 0x2,        0x20000000, 0x4,
    0x10000000, 0x8,        0x8000000,  0x10,       0x4000000,  0x20,
    0x2000000,  0x40,       0x1000000,  0x80,       0x800000,   0x100,
    0x400000,   0x200,      0x200000,   0x400,      0x100000,   0x800,
    0x80000,    0x1000,     0x40000,    0x2000,     0x20000,    0x4000,
    0x1000f,    0xe0008000, 0x8070,     0x1c010000, 0x4180,     0x3020000,
    0x2200,     0x840000,   0x1c00,     0x680000,   0x1800,     0x100000,
    0x1400,     0x300000,   0x2200,     0x480000,   0x4100,     0x840000,
    0x4080,     0x1040000,  0x8040,     0x2020000,  0x8020,     0x4020000,
    0x8010,     0x8020000,  0x10008,    0x10010000, 0x10004,    0x20010000,
    0x10002,    0x40010000, 0x10001,    0x80010000, 0x10001,    0x80010000,
    0x10002,    0x40010000, 0x10004,    0x20010000, 0x8008,     0x10020000,
    0x8010,     0x8020000,  0x8020,     0x4020000,  0x4040,     0x2040000,
    0x4080,     0x1040000,  0x2100,     0x880000,   0x1200,     0x500000,
    0x1400,     0x300000,   0xc00,      0x700000,   0x1200,     0x880000,
    0x2180,     0x3040000,  0x4070,     0x1c020000, 0x800f,     0xe0010000,
    0x10000,    0x8000,     0x20000,    0x4000,     0x40000,    0x2000,
    0x80000,    0x1000,     0x100000,   0x800,      0x200000,   0x400,
    0x400000,   0x200,      0x800000,   0x100,      0x1000000,  0x80,
    0x2000000,  0x40,       0x4000000,  0x20,       0x8000000,  0x10,
    0x10000000, 0x8,        0x20000000, 0x4,        0x40000000, 0x2,
    0x80000000, 0x1};

const BitMap test_pattern64 = {_test_pattern64, 64, 64};
;

static const u32 _test_pattern8[2] = {0x815a245a, 0x5a245a81};

const BitMap test_pattern8 = {_test_pattern8, 8, 8};
;
