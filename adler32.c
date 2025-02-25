/**
 * @file adler32.c
 * @brief Implementation of the Adler-32 checksum algorithm.
 */

#include "adler32.h"

static const u32 MOD_ADLER = 65521;

/* This is pretty slow implementation, but should be good enough for testing
 *   stolen straight from : https://en.wikipedia.org/wiki/Adler-32 */
u32 adler32(unsigned char *data, u32 len) {
    u32 a = 1, b = 0;
    u32 index;

    for (index = 0; index < len; ++index) {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}
