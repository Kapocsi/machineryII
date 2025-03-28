#ifndef _IOCTL_H
#define _IOCTL_H

#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define TIOCGETP (('T' << 8) | 0)
#define TIOCSETP (('T' << 8) | 1)
#define TIOCSETN TIOCSETP
#define TIOCGETC (('T' << 8) | 2)
#define TIOCSETC (('T' << 8) | 3)
#define TIOCGLTC (('T' << 8) | 4)
#define TIOCSLTC (('T' << 8) | 5)
#define TIOCGWINSZ (('T' << 8) | 11)
#define TIOCSWINSZ (('T' << 8) | 12)

#ifdef __MINT__
#define FSTAT (('F' << 8) | 0)
#define FIONREAD (('F' << 8) | 1)
#define FIONWRITE (('F' << 8) | 2)
#define FUTIME (('F' << 8) | 3)
#define FTRUNCATE (('F' << 8) | 4)
#define TIOCGPGRP (('T' << 8) | 6)
#define TIOCSPGRP (('T' << 8) | 7)
#define TIOCFLUSH (('T' << 8) | 8)
#define TIOCSTOP (('T' << 8) | 9)
#define TIOCSTART (('T' << 8) | 10)
#define TIOCGXKEY (('T' << 8) | 13)
#define TIOCSXKEY (('T' << 8) | 14)

#define TIOCIBAUD (('T' << 8) | 18)
#define TIOCOBAUD (('T' << 8) | 19)
#define TIOCCBRK (('T' << 8) | 20)
#define TIOCSBRK (('T' << 8) | 21)
#define TIOCGFLAGS (('T' << 8) | 22)
#define TIOCSFLAGS (('T' << 8) | 23)
#define TIOCOUTQ (('T' << 8) | 24)

/* faked by the library */
#define TIOCMGET (('T' << 8) | 248)
#define TIOCCDTR (('T' << 8) | 249)
#define TIOCSDTR (('T' << 8) | 250)
#define TIOCNOTTY (('T' << 8) | 251)

/* bits in longword fetched by TIOCMGET */
#define TIOCM_LE 0001 /* not supported */
#define TIOCM_DTR 0002
#define TIOCM_RTS 0004
#define TIOCM_ST 0010 /* not supported */
#define TIOCM_SR 0020 /* not supported */
#define TIOCM_CTS 0040
#define TIOCM_CAR 0100
#define TIOCM_CD TIOCM_CAR
#define TIOCM_RNG 0200
#define TIOCM_RI TIOCM_RNG
#define TIOCM_DSR 0400 /* not supported */

/* not yet implemented in MiNT */
#define TIOCGETD (('T' << 8) | 252)
#define TIOCSETD (('T' << 8) | 253)
#define TIOCLGET (('T' << 8) | 254)
#define TIOCLSET (('T' << 8) | 255)

#define NTTYDISC 1

/* ioctl's to act on processes */
#define PPROCADDR (('P' << 8) | 1)
#define PBASEADDR (('P' << 8) | 2)
#define PCTXTSIZE (('P' << 8) | 3)
#define PSETFLAGS (('P' << 8) | 4)
#define PGETFLAGS (('P' << 8) | 5)
#define PTRACESFLAGS (('P' << 8) | 6)
#define PTRACEGFLAGS (('P' << 8) | 7)
#define P_ENABLE (1 << 0) /* enable tracing */
#if 0                     /* NOTYETDEFINED */
#define P_DOS (1 << 1)    /* trace DOS calls - unimplemented */
#define P_BIOS (1 << 2)   /* trace BIOS calls - unimplemented */
#define P_XBIOS (1 << 3)  /* trace XBIOS calls - unimplemented */
#endif

#define PTRACEGO (('P' << 8) | 8) /* these 4 must be together */
#define PTRACEFLOW (('P' << 8) | 9)
#define PTRACESTEP (('P' << 8) | 10)
#define PTRACE11 (('P' << 8) | 11)
#define PLOADINFO (('P' << 8) | 12)
#define PFSTAT (('P' << 8) | 13)

struct __ploadinfo {
    /* passed */
    short fnamelen;
    /* returned */
    char *cmdlin, *fname;
};

/* shared memory ioctl's */
#define SHMGETBLK (('M' << 8) | 0)
#define SHMSETBLK (('M' << 8) | 1)

/* cursor control ioctl's */
#define TCURSOFF (('c' << 8) | 0)
#define TCURSON (('c' << 8) | 1)
#define TCURSBLINK (('c' << 8) | 2)
#define TCURSSTEADY (('c' << 8) | 3)
#define TCURSSRATE (('c' << 8) | 4)
#define TCURSGRATE (('c' << 8) | 5)
#endif /* __MINT__ */

#ifndef _filesys_h
struct tchars {
    char t_intrc;
    char t_quitc;
    char t_startc;
    char t_stopc;
    char t_eofc;
    char t_brkc;
};

struct ltchars {
    char t_suspc;
    char t_dsuspc;
    char t_rprntc;
    char t_flushc;
    char t_werasc;
    char t_lnextc;
};

#define CRMOD 0x0001
#define CBREAK 0x0002
#ifndef _TERMIOS_H
#define ECHO 0x0004
#endif /* _TERMIOS_H */
#define XTABS 0x0008
#define RAW 0x0010
#define LCASE 0x0020 /* does nothing */
#ifndef _TERMIOS_H
#define NOFLSH 0x0040
#ifdef __MINT__
#define TOSTOP 0x0100
#endif /* __MINT__ */
#endif /* _TERMIOS_H */
#define TANDEM 0x1000
#define _RTSCTS 0x2000
#define EVENP 0x4000
#define ODDP 0x8000
#define ANYP (0)
#endif /* _filesys_h */

#ifndef _TERMIOS_H
#define B0 0
#define B50 1
#define B75 2
#define B110 3
#define B134 4
#define B135 4
#define B150 5
#define B200 6
#define B300 7
#define B600 8
#define B1200 9
#define B1800 10
#define B2400 11
#define B4800 12
#define B9600 13
#define B19200 14
#define B38400 15
#endif

/* The ones below aren't supported by the kernel, at least not yet */
#define VTDELAY 0
#define ALLDELAY 0

#ifdef __MINT__

#define XKEY 0x0200

#ifndef _filesys_h
struct xkey {
    short xk_num;
    char xk_def[8];
};
#endif

/* some fake defines for the line discipline stuff */

#define LCRTBS 0x01
#define LCRTERA 0x02
#define LCRTKIL 0x04
#define LPRTERA 0x10
#define LFLUSHO 0x20
#define LLITOUT 0x100

#else

#define META 0x0100 /* extension: Alternate as meta key */
#define PASS8 0x0100

#endif /* __MINT__ */

#ifndef _filesys_h
struct sgttyb {
    char sg_ispeed;
    char sg_ospeed;
    char sg_erase;
    char sg_kill;
    short sg_flags;
};

struct winsize {
    short ws_row;
    short ws_col;
    short ws_xpixel;
    short ws_ypixel;
};
#endif

struct _mutimbuf {
    unsigned short actime, acdate; /* GEMDOS format */
    unsigned short modtime, moddate;
};

__EXTERN int ioctl __PROTO((int, int, void *));
__EXTERN int stty __PROTO((int, struct sgttyb *));
__EXTERN int gtty __PROTO((int, struct sgttyb *));

#ifdef __cplusplus
}
#endif

#endif /* _IOCTL_H */
