/*
 *	TIME.H		Date/Time related definitions
 *	 ansi draft sec  4.12
 */

#ifndef _TIME_H
#define _TIME_H

#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCKS_PER_SEC ((clock_t)200) /* clock ticks per second */
#define CLK_TCK CLOCKS_PER_SEC        /* old name for this */

#ifndef NULL
#define NULL __NULL
#endif

#ifndef _TIME_T
#define _TIME_T long
typedef _TIME_T time_t;
#endif

#ifndef _SIZE_T
#define _SIZE_T __SIZE_TYPEDEF__
typedef _SIZE_T size_t;
#endif

typedef unsigned long clock_t;

struct tm {
  int tm_sec;   /* seconds (0..59) */
  int tm_min;   /* minutes (0..59) */
  int tm_hour;  /* hours (0..23) */
  int tm_mday;  /* day of month (1..31) */
  int tm_mon;   /* month (0..11) */
  int tm_year;  /* year - 1900 */
  int tm_wday;  /* day of week (0=Sun..6=Sat) */
  int tm_yday;  /* day of year (0..365) */
  int tm_isdst; /* daylight saving?  */
};

#ifndef __STRICT_ANSI__
struct timeval {
  long tv_sec;  /* seconds */
  long tv_usec; /* microseconds */
};

struct timezone {
  int tz_minuteswest; /* minues west of GMT */
  int tz_dsttime;     /* daylight savings time correction */
};
#endif

__EXTERN clock_t clock __PROTO((void));
__EXTERN double difftime __PROTO((time_t, time_t));
__EXTERN time_t mktime __PROTO((const struct tm *));
__EXTERN time_t time __PROTO((time_t *));
__EXTERN char *asctime __PROTO((const struct tm *));
__EXTERN char *ctime __PROTO((const time_t *));
__EXTERN struct tm *gmtime __PROTO((const time_t *));
__EXTERN struct tm *localtime __PROTO((const time_t *));
__EXTERN __SIZE_TYPEDEF__ strftime __PROTO((char *s, size_t maxsize,
                                            const char *format,
                                            const struct tm *timeptr));

/* violation of ANSI standard, but POSIX wants it... sigh */
__EXTERN void tzset __PROTO((void));

#if !defined(__STRICT_ANSI__) && !defined(_POSIX_SOURCE)
__EXTERN clock_t _clock __PROTO((void));
__EXTERN int gettimeofday __PROTO((struct timeval *, struct timezone *));
__EXTERN int settimeofday __PROTO((struct timeval *, struct timezone *));

#ifndef _FD_SET_T
#define _FD_SET_T unsigned long
typedef _FD_SET_T fd_set;
#endif

__EXTERN int select __PROTO((int, fd_set *, fd_set *, fd_set *,
                             struct timeval *));

#define timercmp(tva, tvb, op)                                                 \
  ((tva)->tv_sec op(tvb)->tv_sec ||                                            \
   ((tva)->tv_sec == (tvb)->tv_sec && (tva)->tv_usec op(tvb)->tv_usec))
#endif

#ifdef __cplusplus
}
#endif

#endif /* _TIME_H */
