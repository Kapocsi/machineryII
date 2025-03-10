# 1 "src/main.c" 1
# 1 "include/font.h" 1
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
# 13 "include/font.h" 2
# 1 "include/raster.h" 1
# 1 "include/global.h" 1
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
# 14 "include/font.h" 2
# 22 "include/font.h"
extern const u32 glyphs[128][4];
# 30 "include/font.h"
extern const BitMap depixel[];
# 42 "include/font.h"
void drawSmallText(Screen *base, char *str, u32 text_len, u16 x, u16 y,
                   BitMapDrawMode drawMode);
# 55 "include/font.h"
void drawBigText(Screen *base, char *str, u32 text_len, u16 x, u16 y,
                 BitMapDrawMode drawMode);
# 1 "src/main.c" 2
# 1 "include/global.h" 1
# 2 "src/main.c" 2
# 1 "include/input.h" 1



typedef void (*Vector)();

typedef struct {
    int x;
    int y;
} Mouse;

typedef volatile struct {
    Mouse mouse;
} inputState;

inputState *initInput();
void deinitInput();
# 3 "src/main.c" 2
# 1 "include/raster.h" 1
# 4 "src/main.c" 2
# 1 "include/screen.h" 1
# 1 "include/global.h" 1
# 4 "include/screen.h" 2


typedef enum { Original, Primary, Secondary } ScreenBuffer;
# 15 "include/screen.h"
void switchBuffer(ScreenBuffer switch_to);
Screen **initScreen();
# 6 "src/main.c" 2
# 1 "C:/c68/include/assert.h" 1
# 19 "C:/c68/include/assert.h"
 void __eprintf (const char *expression, const long line,				 const char *filename) ;

 void  abort (void) ;
# 7 "src/main.c" 2
# 1 "C:/c68/include/osbind.h" 1
# 8 "src/main.c" 2
# 1 "C:/c68/include/stdio.h" 1
# 9 "src/main.c" 2


void disable_cursor() {
    printf("\033f");
    fflush((&_iob[1]) );
}

void enable_cursor() {
    printf("\033e");
    fflush((&_iob[1]) );
}

u32 tickSinceInception() {
    long ssp = _trap_1_wl((short)0x20,(long)(0)) ;
    u32 ticks = *(u32 *)(0x462);
    _trap_1_wl((short)0x20,(long)(ssp)) ;

    return ticks;
}

int main(int argc, char *argv[]) {
    Screen **screens = initScreen();
    inputState *input = initInput();
    Screen *base;
    BitMap c = {glyphs['*'], 8, 16};
    int i;

    base = screens[Primary];

    switchBuffer(Primary);

    drawBitMap(base, &c, 0, 0, SET);

    (void)_trap_14_w((short)0x25) ;

    while (1)
        ;

    switchBuffer(Original);

    deinitInput();
    return 0;
}
