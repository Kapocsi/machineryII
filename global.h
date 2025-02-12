/**
 * @file global.h
 * @brief Declares globally used constants and types.
 *
 * This header file contains definitions for common numeric types,
 * screen-related type aliases, color enumerations, and global constants.
 * It follows the Rust-style naming convention for type definitions.
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef __C68__
#include <osbind.h>
#else
#include <stdlib.h>
#define Pterm(rv) exit(rv)
#endif

#include <stdio.h>

/* --------------------------------  Types  -------------------------------- */

/**
 * @typedef u8
 * @brief 8-bit unsigned integer.
 */
typedef unsigned char u8;

/**
 * @typedef u16
 * @brief 16-bit unsigned integer.
 */
typedef unsigned int u16;

/**
 * @typedef u32
 * @brief 32-bit unsigned integer.
 */
typedef unsigned long u32;

/**
 * @typedef i8
 * @brief 8-bit signed integer.
 */
typedef char i8;

/**
 * @typedef i16
 * @brief 16-bit signed integer.
 */
typedef int i16;

/**
 * @typedef i32
 * @brief 32-bit signed integer.
 */
typedef long i32;

/**
 * @typedef Screen
 * @brief Type alias for an unsigned long representing a screen.
 *
 * Screens are frequently passed around in the program, so this alias
 * helps avoid simple errors.
 */
typedef unsigned long Screen;

/**
 * @enum Color
 * @brief Defines color constants.
 *
 * This enumeration represents black and white color values,
 * using 1 for black and 0 for white.
 */
typedef enum { BLACK = 1, WHITE = 0 } Color;

/**
 * @enum Bool
 * @brief Boolean enumeration.
 *
 * Defines `True` as 1 and `False` as 0 for boolean operations.
 */
enum Bool { True = 1, False = 0 };

/* ------------------------------  CONSTANTS  ------------------------------ */

/**
 * @brief Screen width in pixels.
 */
#define SCREEN_WIDTH 640l

/**
 * @brief Screen height in pixels.
 */
#define SCREEN_HEIGHT 400l

/**
 * @brief Screen buffer size calculation.
 *
 * The buffer size is determined by dividing the screen width by the
 * number of bits in a `long` (assumed to be 32) and multiplying by
 * the screen height.
 */
#define SCREEN_BUFFER_SIZE (SCREEN_WIDTH / (sizeof(long) * 8)) * SCREEN_HEIGHT

/* -------------------------------  MACROS  -------------------------------- */

/**
 * @brief Marks a function as not yet implemented.
 *
 * This macro prints an error message with the filename and line number,
 * then terminates the program with a nonzero exit code.
 */
#define TODO()                                                                 \
    printf("%s::%d : Unimplemented Function! Exiting.\n", __FILE__, __LINE__); \
    Pterm(-1);

#endif /* GLOBAL_H */
