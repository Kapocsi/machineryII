/**
 * @file adler32.h
 * @brief Header for Adler-32 checksum computation.
 */

#ifndef CRC32_H
#define CRC32_H

#include "../global.h"

/**
 * @brief Computes the Adler-32 checksum for a data buffer.
 * @param data Pointer to the data buffer.
 * @param len Length of the buffer in bytes.
 * @return Computed Adler-32 checksum.
 */
u32 adler32(unsigned char *data, u32 len);

#endif
