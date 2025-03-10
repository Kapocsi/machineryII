#include "global.h"

static const u32 _cursor[8] = {0xf000,  0x3f000, 0x5f000, 0x6f000,
                               0xf7000, 0xfb000, 0xfd000, 0xfe000};

const BitMap cursor = {_cursor, 32, 8};
;

/* const BitMap test = {array, 64, 32}; */
