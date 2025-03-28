#ifndef _VARARGS_H
#define _VARARGS_H

#ifdef __TURBOC__
#error varargs not implemented under Turbo C / Pure C
#endif

/* in case stdarg.h got included by a header file */
#ifdef va_start
#undef va_start
#undef va_end
#undef va_dcl
#undef va_alist
#undef va_list
#endif

#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GNUC__
/* I'm not sure this is right.  These apparently are all supposed to be
   defines; doesn't seem to make much sense to make them functions.
   There may be some missing from this list; these are the ones I found
   by grepping around in code...
*/

/* a va_list is a list of random frobules */
typedef __VA_LIST__ va_list;

/* the address of the list??? don't we already have that???  C programmers
   pick the wierdest times to start worrying about abstractions! */
#define va_start(args) args = (va_list) & va_alist

/* is this supposed to do anything??? */
#define va_end(args)

/* This is apparently a general purpose accessor, used for storing, as
   well as snarfing.  This is the only way I could think of to make it
   work that way.  Please, somebody, re-write this! */
#define va_arg(args, elt_type) ((elt_type *)((args) += sizeof(elt_type)))[-1]

#define va_dcl int va_alist;

#else

/* These macros implement traditional (non-ANSI) varargs
   for GNU C.  */
#if __GNUC__ > 1
#define __va_ellipsis ...
#else
#define __va_ellipsis
#endif

#define va_alist __builtin_va_alist
/* The ... causes current_function_varargs to be set in cc1.  */
#define va_dcl                                                                 \
    int __builtin_va_alist;                                                    \
    __va_ellipsis

/* Define __gnuc_va_list, just as in stdarg.h.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef void *__gnuc_va_list;
#endif

#define va_start(AP) AP = (char *)&__builtin_va_alist
#define va_end(AP)

#define __va_rounded_size(TYPE)                                                \
    (((sizeof(TYPE) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#define va_arg(AP, TYPE)                                                       \
    (AP = (__gnuc_va_list)((char *)(AP) + __va_rounded_size(TYPE)),            \
     *((TYPE *)(void *)((char *)(AP) - ((sizeof(TYPE) < sizeof(int)            \
                                             ? sizeof(TYPE)                    \
                                             : __va_rounded_size(TYPE))))))

#ifndef _VA_LIST_
#define _VA_LIST_
typedef __gnuc_va_list va_list;
#endif /* _VA_LIST_ */

#endif /* __GNUC__ */

#ifdef __cplusplus
}
#endif

#endif /* _VARARGS_H */
