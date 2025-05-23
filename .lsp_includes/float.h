/*
 * float.h
 *	see sec 2.2.4.2 and 4.1.3 of ansi draft
 *
 *	this implementation strives to meet these values, but actually
 *	does'nt quite make it, so we lie (the file was produced by gcc
 *	compiled config.c on a Sun).
 *	i need help here!
 *		++jrb
 */
#ifndef _FLOAT_H
#define _FLOAT_H

#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __TURBOC__
#include <tcfloat.h>
#else

#ifdef __SOZOBON__

/* 4/19/92 sb
   These constants correspond to version 2.0 of David Brooks' floating point
   library, which Sozobon 1.33i uses. */

/* Radix of exponent representation */
#define FLT_RADIX 2
/* Number of base-FLT_RADIX digits in the significand of a float */
#define FLT_MANT_DIG 24
/* Number of decimal digits of precision in a float */
#define FLT_DIG 7
/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
#define FLT_ROUNDS 1
/* Difference between 1.0 and the minimum float greater than 1.0 */
#define FLT_EPSILON ((float)1.192092891e-07)
/* Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#define FLT_MIN_EXP (-63)
/* Minimum normalised float */
#define FLT_MIN ((float)5.421010547e-20)
/* Minimum int x such that 10**x is a normalised float */
#define FLT_MIN_10_EXP (-19)
/* Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#define FLT_MAX_EXP 64
/* Maximum float */
#define FLT_MAX ((float)9.2233715e18)
/* Maximum int x such that 10**x is a representable float */
#define FLT_MAX_10_EXP 18

/* double is identical to float */
#define DBL_MANT_DIG FLT_MANT_DIG
#define DBL_DIG FLT_DIG
#define DBL_ROUNDS FLT_ROUNDS
#define DBL_EPSILON ((double)FLT_EPSILON)
#define DBL_MIN_EXP FLT_MIN_EXP
#define DBL_MIN ((double)FLT_MIN)
#define DBL_MIN_10_EXP FLT_MIN_10_EXP
#define DBL_MAX_EXP FLT_MAX_EXP
#define DBL_MAX ((double)FLT_MAX)
#define DBL_MAX_10_EXP FLT_MAX_10_EXP

/* so is long double */
#define LDBL_MANT_DIG FLT_MANT_DIG
#define LDBL_DIG FLT_DIG
#define LDBL_ROUNDS FLT_ROUNDS
#define LDBL_EPSILON ((long double)FLT_EPSILON)
#define LDBL_MIN_EXP FLT_MIN_EXP
#define LDBL_MIN ((long double)FLT_MIN)
#define LDBL_MIN_10_EXP FLT_MIN_10_EXP
#define LDBL_MAX_EXP FLT_MAX_EXP
#define LDBL_MAX ((long double)FLT_MAX)
#define LDBL_MAX_10_EXP FLT_MAX_10_EXP

#else /* __SOZOBON__ */

/* float.h */
/* Produced by config version 4.2, CWI, Amsterdam */

/* Radix of exponent representation */
#define FLT_RADIX 2
/* Number of base-FLT_RADIX digits in the significant of a float */
#define FLT_MANT_DIG 24
/* Number of decimal digits of precision in a float */
#define FLT_DIG 6
/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
#define FLT_ROUNDS 1
/* Difference between 1.0 and the minimum float greater than 1.0 */
#define FLT_EPSILON 1.19209290e-07F
/* Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#define FLT_MIN_EXP (-125)
/* Minimum normalised float */
#define FLT_MIN 1.17549435e-38F
/* Minimum int x such that 10**x is a normalised float */
#define FLT_MIN_10_EXP (-37)
/* Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#define FLT_MAX_EXP 128
/* Maximum float */
#define FLT_MAX 3.40282347e+38F
/* Maximum int x such that 10**x is a representable float */
#define FLT_MAX_10_EXP 38

/* Number of base-FLT_RADIX digits in the significand of a double */
#define DBL_MANT_DIG 53
/* Number of decimal digits of precision in a double */
#define DBL_DIG 15
/* Difference between 1.0 and the minimum double greater than 1.0 */
#define DBL_EPSILON 2.2204460492503131e-16
/* Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#define DBL_MIN_EXP (-1021)
/* Minimum normalised double */
#define DBL_MIN 2.2250738585072014e-308
/* Minimum int x such that 10**x is a normalised double */
#define DBL_MIN_10_EXP (-307)
/* Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#define DBL_MAX_EXP 1024
/* Maximum double */
#define DBL_MAX 1.7976931348623157e+308
/* Maximum int x such that 10**x is a representable double */
#define DBL_MAX_10_EXP 308

/* Number of base-FLT_RADIX digits in the significand of a long double */
#undef LDBL_MANT_DIG
#define LDBL_MANT_DIG 64
/* Number of decimal digits of precision in a long double */
#undef LDBL_DIG
#define LDBL_DIG 18
/* Difference between 1.0 and the minimum long double greater than 1.0 */
#undef LDBL_EPSILON
#define LDBL_EPSILON 1.084202172485504434001e-19L
/* Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#undef LDBL_MIN_EXP
#define LDBL_MIN_EXP (-16382)
/* Minimum normalised long double */
#undef LDBL_MIN
#define LDBL_MIN 1.68105157155604675313e-4932L
/* Minimum int x such that 10**x is a normalised long double */
#undef LDBL_MIN_10_EXP
#define LDBL_MIN_10_EXP (-4931)
/* Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#undef LDBL_MAX_EXP
#define LDBL_MAX_EXP 16384
/* Maximum long double */
#undef LDBL_MAX
#define LDBL_MAX 1.18973149535723176502e4932L
/* Maximum int x such that 10**x is a representable long double */
#undef LDBL_MAX_10_EXP
#define LDBL_MAX_10_EXP 4932

#endif /* __SOZOBON__ */

#endif /* __TURBOC__ */

#endif /* _FLOAT_H */
