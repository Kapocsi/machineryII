/*
 * @file global.h
 * @brief Declare globally used constants and types that will be used in more
 * files than not.
 */

#ifndef global_h
#define global_h

/*
 * Define common numeric types following
 * the rust style convention of 'xNN':
 * where 'X' is:
 *  - 'u' for Unsigned,
 *  - 'i' for sIgned,
 *  - 'f' for Floating-Point;
 *  and 'NN' is the number of bits for each
 * number.
 */
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
typedef char i8;
typedef int i16;
typedef long i32;

/*
 * We always pass around screens, it makes sense that we should have a type
 * alias for this to avoid simple errors.
 */
typedef unsigned char Screen;

enum Color { BLACK, WHITE };

#endif
