# 1 "src/raster.c" 1
# 1 "include/raster.h" 1
# 1 "include/global.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 14 "include/global.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 20 "C:/c68/include/stdio.h"
typedef unsigned long  size_t;
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 20 "include/global.h" 2
# 28 "include/global.h"
typedef unsigned char u8;





typedef unsigned int u16;





typedef unsigned long u32;





typedef char i8;





typedef int i16;





typedef long i32;
# 67 "include/global.h"
typedef u32 Screen;
# 77 "include/global.h"
typedef struct {

    const u32 *longs;
    const u8 width;
    const u8 height;
} BitMap;
# 91 "include/global.h"
typedef enum { BLACK = 1, WHITE = 0 } Color;
# 99 "include/global.h"
enum Bool { True = 1, False = 0 };
# 12 "include/raster.h" 2
# 21 "include/raster.h"
typedef enum {
    SET,
    UNSET
} BitMapDrawMode;
# 31 "include/raster.h"
void black_screen(Screen *base);
# 38 "include/raster.h"
void white_screen(Screen *base);
# 48 "include/raster.h"
void set_pixel(Screen *base, u16 x, u16 y, Color color);
# 63 "include/raster.h"
void drawBitMap(Screen *base, const BitMap *bitmap, u16 x_offset, u16 y_offset,
                BitMapDrawMode draw_mode);
# 74 "include/raster.h"
void drawVerticalLine(Screen *base, u16 x_pos, u16 y_start, u16 y_end);
# 84 "include/raster.h"
void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end);
# 1 "src/raster.c" 2
# 1 "include/global.h" 1
# 2 "src/raster.c" 2
# 1 "C:/c68/include/assert.h" 1
# 19 "C:/c68/include/assert.h"
 void __eprintf (const char *expression, const long line,				 const char *filename) ;

 void  abort (void) ;
# 3 "src/raster.c" 2
# 1 "C:/c68/include/stdio.h" 1
# 4 "src/raster.c" 2
# 10 "src/raster.c"
static u32 min(u32 a, u32 b) {
    if (a > b)
        return b;
    return a;
}

static u32 max(u32 a, u32 b) {
    if (a > b)
        return a;
    else
        return b;
}

void black_screen(Screen *base) {
    register int i = 0;

    if (base == ((void *)0) )
        return;

    for (i = 0; i < (640l  / (sizeof(long) * 8)) * 400l ; i++) {
        base[i] = ~0L;
    }
}

void white_screen(Screen *base) {
    register int i = 0;

    if (base == ((void *)0) )
        return;

    for (i = 0; i < (640l  / (sizeof(long) * 8)) * 400l ; i++) {
        base[i] = 0;
    }
}

void set_pixel(Screen *base, u16 x, u16 y, Color color) {





    const u32 lmb = 0x0000000000000001;
    register u32 bitmap = lmb >> (x & 31);

    register u32 offset = (x >> 5) + (y << 4) + (y << 2) ;

    base[offset] = (base[offset] & ~bitmap) | (-color & bitmap);
}
# 98 "src/raster.c"
static void drawBitMap8(Screen *screen, const BitMap *bitmap,                                          const u16 x_start, const u16 y_start,                                          BitMapDrawMode draw_mode) {                           u8 *base = (u8 *)screen;                                             u8 *bmaps = (u8 *)bitmap->longs;                                     u16 x, y;                                                                                                                                                                                             if (x_start % 8 != 0)                                                           printf("%d\n", x_start);                                                   ((x_start % 8 == 0) ? 0 :     ( __eprintf("x_start % 8 == 0",(long)(98), "src/raster.c"), abort(), 0 )) ;                                                                                                                                  base += y_start * (640l  / 8);                     base += x_start / 8;                                                                                                                     for (y = 0; y < bitmap->height; y++) {                                             for (x = 0; x < bitmap->width / 8; x++) {                                       switch (draw_mode) {                                                           case (SET):                                                                        *base++ |= *bmaps++;                                                           break;                                                                     case (UNSET):                                                                      *base++ &= ~(*bmaps++);                                                        break;                                                                     }                                                                          }                                                                              base += (640l  / 8) - x;                                         }                                                                          } ;
static void drawBitMap16(Screen *screen, const BitMap *bitmap,                                          const u16 x_start, const u16 y_start,                                          BitMapDrawMode draw_mode) {                           u16 *base = (u16 *)screen;                                             u16 *bmaps = (u16 *)bitmap->longs;                                     u16 x, y;                                                                                                                                                                                             if (x_start % 16 != 0)                                                           printf("%d\n", x_start);                                                   ((x_start % 16 == 0) ? 0 :     ( __eprintf("x_start % 16 == 0",(long)(99), "src/raster.c"), abort(), 0 )) ;                                                                                                                                  base += y_start * (640l  / 16);                     base += x_start / 16;                                                                                                                     for (y = 0; y < bitmap->height; y++) {                                             for (x = 0; x < bitmap->width / 16; x++) {                                       switch (draw_mode) {                                                           case (SET):                                                                        *base++ |= *bmaps++;                                                           break;                                                                     case (UNSET):                                                                      *base++ &= ~(*bmaps++);                                                        break;                                                                     }                                                                          }                                                                              base += (640l  / 16) - x;                                         }                                                                          } ;
static void drawBitMap32(Screen *screen, const BitMap *bitmap,                                          const u16 x_start, const u16 y_start,                                          BitMapDrawMode draw_mode) {                           u32 *base = (u32 *)screen;                                             u32 *bmaps = (u32 *)bitmap->longs;                                     u16 x, y;                                                                                                                                                                                             if (x_start % 32 != 0)                                                           printf("%d\n", x_start);                                                   ((x_start % 32 == 0) ? 0 :     ( __eprintf("x_start % 32 == 0",(long)(100), "src/raster.c"), abort(), 0 )) ;                                                                                                                                  base += y_start * (640l  / 32);                     base += x_start / 32;                                                                                                                     for (y = 0; y < bitmap->height; y++) {                                             for (x = 0; x < bitmap->width / 32; x++) {                                       switch (draw_mode) {                                                           case (SET):                                                                        *base++ |= *bmaps++;                                                           break;                                                                     case (UNSET):                                                                      *base++ &= ~(*bmaps++);                                                        break;                                                                     }                                                                          }                                                                              base += (640l  / 32) - x;                                         }                                                                          } ;

void drawBitMap(Screen *base, const BitMap *bitmap, const u16 x_start,
                const u16 y_start, BitMapDrawMode draw_mode) {
    u16 alignment = min(bitmap->width & 31, x_start & 31);
    if (alignment == 0)
        alignment = max(bitmap->width & 31, x_start & 31);



    if (base == ((void *)0)  || bitmap == ((void *)0)  || bitmap->longs == ((void *)0) )
        return;

    switch (alignment) {
    case 0:
        drawBitMap32(base, bitmap, x_start, y_start, draw_mode);
        break;
    case 16:
        drawBitMap16(base, bitmap, x_start, y_start, draw_mode);
        break;
    case 8:
    case 24:
        drawBitMap8(base, bitmap, x_start, y_start, draw_mode);
        break;
    default:
        printf("%d\n", alignment);
    }
}

void drawVerticalLine(Screen *base, u16 x, u16 y_start, u16 y_end) {


    u16 y = (y_start << 4) + (y_start << 2);


    u16 y_limit = (y_end << 4) + (y_end << 2);


    u32 x_offset = x >> 5;


    u32 lmb = 1l << 31;

    u32 bitmap = lmb >> (x & 31);

    for (; y <= y_limit; y += 20) {
        base[x_offset + y] |= bitmap;
    }
}

void drawHorizontalLine(Screen *base, u16 y_pos, u16 x_start, u16 x_end) {


    u8 x = x_start >> 5;

    u8 x_limit = x_end >> 5;


    u16 y_offset = (y_pos << 4) + (y_pos << 2);


    u32 s_offset = x_start & 31;

    u32 e_offset = x_end & 31;

    if (x < x_limit) {

        base[x + y_offset] |= ~0L >> s_offset;
        x++;


        for (; x < x_limit; x++) {
            base[x + y_offset] = ~0L;
        }


        base[x + y_offset] |= ~(~0L >> e_offset);

    } else {
        base[x + y_offset] |= (~0L >> s_offset) ^ (~0L >> e_offset);
    }
};
