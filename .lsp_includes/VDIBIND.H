#ifndef _VDIBIND_H
#define _VDIBIND_H

#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T
#include <stddef.h>
#endif

__EXTERN int vswr_mode __PROTO((int handle, int mode));
__EXTERN void vs_color __PROTO((int handle, int index, int rgb[]));
__EXTERN int vsl_type __PROTO((int handle, int style));
__EXTERN void vsl_udsty __PROTO((int handle, int pat));
__EXTERN int vsl_width __PROTO((int handle, int width));
__EXTERN int vsl_color __PROTO((int handle, int index));
__EXTERN void vsl_ends __PROTO((int handle, int begstyle, int endstyle));
__EXTERN int vsm_type __PROTO((int handle, int symbol));
__EXTERN void vsm_height __PROTO((int handle, int height));
__EXTERN int vsm_color __PROTO((int handle, int index));
__EXTERN int vst_height __PROTO((int handle, int height, int *charw, int *charh,
                                 int *cellw, int *cellh));
__EXTERN int vst_point __PROTO((int handle, int point, int *charw, int *charh,
                                int *cellw, int *cellh));
__EXTERN int vst_rotation __PROTO((int handle, int ang));
__EXTERN int vst_font __PROTO((int handle, int font));
__EXTERN int vst_color __PROTO((int handle, int index));
__EXTERN int vst_effects __PROTO((int handle, int effects));
__EXTERN void vst_alignment __PROTO((int handle, int hin, int vin, int *hout,
                                     int *vout));
__EXTERN int vsf_interior __PROTO((int handle, int style));
__EXTERN int vsf_fill __PROTO((int handle, int style));
__EXTERN int vsf_style __PROTO((int handle, int style));
__EXTERN int vsf_color __PROTO((int handle, int index));
__EXTERN int vsf_perimeter __PROTO((int handle, int vis));
__EXTERN void vsf_udpat __PROTO((int handle, int pat[], int planes));

__EXTERN void v_opnwk __PROTO((int work_in[], int *handle, int work_out[]));
__EXTERN void v_clswk __PROTO((int handle));
__EXTERN void v_opnvwk __PROTO((int work_in[], int *handle, int work_out[]));
__EXTERN void v_clsvwk __PROTO((int handle));

__EXTERN void v_clrwk __PROTO((int handle));
__EXTERN void v_updwk __PROTO((int handle));
__EXTERN int vst_load_fonts __PROTO((int handle, int select));
__EXTERN void vst_unload_fonts __PROTO((int handle, int select));
__EXTERN void vs_clip __PROTO((int handle, int clip_flag, int pxyarray[]));

__EXTERN void v_bar __PROTO((int handle, int pxyarray[]));
__EXTERN void v_arc __PROTO((int handle, int x, int y, int radius, int begang,
                             int endang));
__EXTERN void v_pieslice __PROTO((int handle, int x, int y, int radius,
                                  int begang, int endang));
__EXTERN void v_circle __PROTO((int handle, int x, int y, int radius));
__EXTERN void v_ellarc __PROTO((int handle, int x, int y, int xrad, int yrad,
                                int begang, int endang));
__EXTERN void v_ellpie __PROTO((int handle, int x, int y, int xrad, int yrad,
                                int begang, int endang));
__EXTERN void v_ellipse __PROTO((int handle, int x, int y, int xrad, int yrad));
__EXTERN void v_rbox __PROTO((int handle, int pxyarray[]));
__EXTERN void v_rfbox __PROTO((int handle, int pxyarray[]));
__EXTERN void v_justified __PROTO((int handle, int x, int y, char *str, int len,
                                   int word_space, int char_space));

__EXTERN int vsin_mode __PROTO((int handle, int dev, int mode));
__EXTERN void vrq_locator __PROTO((int handle, int x, int y, int *xout,
                                   int *yout, int *term));
__EXTERN int vsm_locator __PROTO((int handle, int x, int y, int *xout,
                                  int *yout, int *term));

__EXTERN void vrq_valuator __PROTO((int handle, int in, int *out, int *term));
__EXTERN void vsm_valuator __PROTO((int handle, int in, int *out, int *term,
                                    int *status));
__EXTERN void vrq_choice __PROTO((int handle, int cin, int *cout));
__EXTERN int vsm_choice __PROTO((int handle, int *choice));
__EXTERN void vrq_string __PROTO((int handle, int len, int echo, int echoxy[],
                                  char *str));
__EXTERN int vsm_string __PROTO((int handle, int len, int echo, int echoxy[],
                                 char *str));
__EXTERN void vsc_form __PROTO((int handle, int form[]));
__EXTERN void vex_timv __PROTO((int handle, void *time_addr, void **otime_addr,
                                int *time_conv));
__EXTERN void v_show_c __PROTO((int handle, int reset));
__EXTERN void v_hide_c __PROTO((int handle));
__EXTERN void vq_mouse __PROTO((int handle, int *pstatus, int *x, int *y));
__EXTERN void vex_butv __PROTO((int handle, void *new_p, void **old));
__EXTERN void vex_motv __PROTO((int handle, void *new_p, void **old));
__EXTERN void vex_curv __PROTO((int handle, void *new_p, void **old));
__EXTERN void vq_key_s __PROTO((int handle, int *state));

__EXTERN void vq_extnd __PROTO((int handle, int flag, int work_out[]));
__EXTERN int vq_color __PROTO((int handle, int index, int flag, int rgb[]));
__EXTERN void vql_attribute __PROTO((int handle, int atrib[]));
__EXTERN void vqm_attributes __PROTO((int handle, int atrib[]));
__EXTERN void vqf_attributes __PROTO((int handle, int atrib[]));
__EXTERN void vqt_attributes __PROTO((int handle, int atrib[]));
__EXTERN void vqt_extent __PROTO((int handle, char *str, int extent[]));
__EXTERN int vqt_width __PROTO((int handle, int chr, int *cw, int *ldelta,
                                int *rdelta));
__EXTERN int vqt_name __PROTO((int handle, int element, char *name));
__EXTERN void vq_cellarray __PROTO((int handle, int pxyarray[], int row_len,
                                    int nrows, int *el_used, int *rows_used,
                                    int *status, int color[]));
__EXTERN void vqin_mode __PROTO((int handle, int dev, int *mode));
__EXTERN void vqt_fontinfo __PROTO((int handle, int *minade, int *maxade,
                                    int distances[], int *maxwidth,
                                    int effects[]));
__EXTERN void vqt_font_info __PROTO((int handle, int *minade, int *maxade,
                                     int distances[], int *maxwidth,
                                     int effects[]));

__EXTERN void v_pline __PROTO((int handle, int count, int pxyarray[]));
__EXTERN void v_pmarker __PROTO((int handle, int count, int pxyarray[]));
__EXTERN int v_gtext __PROTO((int handle, int x, int y, char *str));
__EXTERN void v_fillarea __PROTO((int handle, int count, int pxyarray[]));
__EXTERN void v_cellarray __PROTO((int handle, int pxyarray[], int row_length,
                                   int elements, int nrows, int write_mode,
                                   int colarray[]));
__EXTERN void v_contourfill __PROTO((int handle, int x, int y, int index));
__EXTERN void vr_recfl __PROTO((int handle, int pxyarray[]));

__EXTERN void vro_cpyfm __PROTO((int handle, int mode, int pxyarray[],
                                 void *src, void *dst));
__EXTERN void vrt_cpyfm __PROTO((int handle, int mode, int pxyarray[],
                                 void *src, void *dst, int color[]));
__EXTERN void vr_trnfm __PROTO((int handle, void *src, void *dst));
__EXTERN void v_get_pixel __PROTO((int handle, int x, int y, int *pel,
                                   int *indx));

/* Verbose headers. They do seem to leave out the fact that the character
 * coordinates are from (1, 1) (top left corner..).
 */

/*		vq_chcells
 * Inquire addressable Alpha character cells.
 * -1 for no cursor addressing (value for `*n_cols' ? )
 */
__EXTERN void vq_chcells __PROTO((int handle, int *n_rows, int *n_cols));

/*		v_exit_cur
 * Exit alpha mode.
 */
__EXTERN void v_exit_cur __PROTO((int handle));

/*		v_enter_cur
 * Enter alpha mode
 */
__EXTERN void v_enter_cur __PROTO((int handle));

/*		v_curup
 * Alpha cursor up (do nothing if at top).
 */
__EXTERN void v_curup __PROTO((int handle));

/*		v_curdown
 * Alpha cursor down (do nothing if at bottom).
 */
__EXTERN void v_curdown __PROTO((int handle));

/*		v_curright
 * Alpha cursor right (do nothing if at right edge).
 */
__EXTERN void v_curright __PROTO((int handle));

/*		v_curleft
 * Alpha cursor left (do nothing if at left edge).
 */
__EXTERN void v_curleft __PROTO((int handle));

/*		v_curhome
 * Alpha cursor home.
 */
__EXTERN void v_curhome __PROTO((int handle));

/*		v_eeos
 * Erase to end of screen.
 */
__EXTERN void v_eeos __PROTO((int handle));

/*		v_eeol
 * Erase to end of line.
 */
__EXTERN void v_eeol __PROTO((int handle));

/*		vs_curaddress
 * Direct set position.
 */
__EXTERN void vs_curaddress __PROTO((int handle, int row, int col));

/*		v_curtext
 * Output cursor addressable text (string `s').
 */
__EXTERN void v_curtext __PROTO((int handle, char *s));

/*		v_rvon
 * Reverse video on.
 */
__EXTERN void v_rvon __PROTO((int handle));

/*		v_rvoff
 * Reverse video off
 */
__EXTERN void v_rvoff __PROTO((int handle));

/*		vq_curaddress
 * Inquire current cursor address.
 */
__EXTERN void vq_curaddress __PROTO((int handle, int *cur_row, int *cur_col));

/*
 * more vdi esc bindings
 */
__EXTERN int vq_tabstatus __PROTO((int handle));
__EXTERN void v_hardcopy __PROTO((int handle));
__EXTERN void v_dspcur __PROTO((int handle, int x, int y));
__EXTERN void v_rmcur __PROTO((int handle));
__EXTERN void v_form_adv __PROTO((int handle));
__EXTERN void v_output_window __PROTO((int handle, int *pxyarray));
__EXTERN void v_clear_disp_list __PROTO((int handle));
__EXTERN void v_bit_image __PROTO((int handle, const char *filename, int aspect,
                                   int x_scale, int y_scale, int h_align,
                                   int v_align, int *pxyarray));
__EXTERN void vq_scan __PROTO((int handle, int *g_slice, int *g_page,
                               int *a_slice, int *a_page, int *div_fac));
__EXTERN void v_alpha_text __PROTO((int handle, const char *string));
__EXTERN int vs_palette __PROTO((int handle, int palette));
__EXTERN void v_sound __PROTO((int handle, int frequency, int duration));
__EXTERN int vs_mute __PROTO((int handle, int action));
__EXTERN void vt_resolution __PROTO((int handle, int xres, int yres, int *xset,
                                     int *yset));
__EXTERN void vt_axis __PROTO((int handle, int xres, int yres, int *xset,
                               int *yset));
__EXTERN void vt_origin __PROTO((int handle, int xorigin, int yorigin));
__EXTERN void vq_dimensions __PROTO((int handle, int *xdimension,
                                     int *ydimension));
__EXTERN void vt_alignment __PROTO((int handle, int dx, int dy));
__EXTERN void vsp_film __PROTO((int handle, int index, int lightness));
__EXTERN int vqp_filmname __PROTO((int handle, int index, char *name));
__EXTERN void vsc_expose __PROTO((int handle, int state));
__EXTERN void v_meta_extents __PROTO((int handle, int min_x, int min_y,
                                      int max_x, int max_y));
__EXTERN void v_write_meta __PROTO((int handle, int num_intin, int *a_intin,
                                    int num_ptsin, int *a_ptsin));
__EXTERN void vm_pagesize __PROTO((int handle, int pgwidth, int pgheight));
__EXTERN void vm_coords __PROTO((int handle, int llx, int lly, int urx,
                                 int ury));
__EXTERN void vm_filename __PROTO((int handle, const char *filename));
__EXTERN void v_escape2000 __PROTO((int handle, int times));

/* is gdos present */

/* return values for vq_vgdos() inquiry */
#define GDOS_NONE -2L        /* no GDOS installed */
#define GDOS_FSM 0x5F46534DL /* '_FSM' */
#define GDOS_FNT 0x5F464E54L /* '_FNT' */

#ifdef __GNUC_INLINE__
#define vq_vgdos()                                                             \
  ({                                                                           \
    register unsigned long ret __asm__("d0");                                  \
    __asm__ volatile("					\
		movq	#-2,d0;			\
		trap	#2 "                                                  \
                     : "=r"(ret) /* output */                                  \
                     :                                                         \
                     : "d0", "d1", "d2", "a0", "a1", "a2" /* clobbered regs */ \
    );                                                                         \
    ret;                                                                       \
  })
#else
__EXTERN unsigned long vq_gdos __PROTO((void));
#endif /* __GNUC__ | !__NO_INLINE__ */

/* FSM/SpeedGDOS bindings */

/* Get Character Bitmap Information. This call provides information to allow
 * the caller to know the exact size and placement of a given character.  This
 * information includes the character's x and y advance vectors, the x and y
 * offsets, and the bitmap dimensions of the character. The advance vector
 * represents the amount to add to the current point to place the following
 * character.  The x and y offsets, when added to the current point, give the
 * caller the location of the upper left hand corner of the bitmap.  The width
 * and height of the bitmap are returned as 16 bit integers.  All other values
 * are returned in fix31 representation.
 */
__EXTERN void v_getbitmap_info __PROTO((int handle, int ch, long *advancex,
                                        long *advancey, long *xoffset,
                                        long *yoffset, int *width, int *height,
                                        short **bitmap));

/*
 * Inquire text extent, accounting for FSM text placement
 */
__EXTERN void vqt_f_extent __PROTO((int handle, const char *str, int extent[]));

/*
 * Draw outline font text (accounts for fractional advances in rotated text)
 */
__EXTERN void v_ftext __PROTO((int handle, int x, int y, const char *str));
__EXTERN void v_ftext_offset __PROTO((int handle, int x, int y, const char *str,
                                      int *offset));

/*
 * Generate an outline for character ch, and return the address of the outline.
 */
__EXTERN void v_getoutline __PROTO((int handle, int ch, int *xyarray,
                                    char *bezarray, int maxverts,
                                    int *numverts));

/*
 * Set scratch buffer allocation mode.
 * mode=0: (default) account for FSM fonts when allocating scratch buffers
 * mode=1: account only for BM fonts
 * mode=2: allocate no scratch buffer
 */
__EXTERN void vst_scratch __PROTO((int handle, int mode));

/*
 * Set FSM error mode.
 * mode=1: (default) errors go to screen.
 * mode=0: errors reported in error variable `errorvar'.
 *   NOTICE: the pointer for errorvar is a pointer to short
 *           (in 32 bit mode it would make a difference)
 */
__EXTERN void vst_error __PROTO((int handle, int mode, short *errorvar));

/*
 * v_gtext with optional shadow attribute
 */
__EXTERN void v_shtext __PROTO((int wsid, int x, int y, const char *text,
                                int color, int xshadow, int yshadow));

/*
 * Set character cell height by arbitrary points.
 */
__EXTERN int vst_arbpt __PROTO((int handle, int point, int *wchar, int *hchar,
                                int *wcell, int *hcell));
__EXTERN long vst_arbpt32 __PROTO((int handle, long point, int *wchar,
                                   int *hchar, int *wcell, int *hcell));

/*
 * Inquire outline font text advance placement vector.
 */
__EXTERN void vqt_advance __PROTO((int handle, int ch, int *xadv, int *yadv,
                                   int *xrem, int *yrem));
__EXTERN void vqt_advance32 __PROTO((int handle, int ch, long *advx,
                                     long *advy));

/*
 * Inquire device status information.
 */
__EXTERN void vqt_devinfo __PROTO((int handle, int device, int *isdev,
                                   char *drivername));

/*
 * Save FSM cache to disk.
 */
__EXTERN int v_savecache __PROTO((int handle, char *filename));

/*
 * Load/merge FSM cache from disk.
 */
__EXTERN int v_loadcache __PROTO((int handle, char *filename, int mode));

/*
 * Flush FSM cache.
 */
__EXTERN int v_flushcache __PROTO((int handle));

/*
 * Set character cell width by arbitrary points.
 */
__EXTERN int vst_setsize __PROTO((int handle, int point, int *wchar, int *hchar,
                                  int *wcell, int *hcell));
__EXTERN long vst_setsize32 __PROTO((int handle, long point, int *wchar,
                                     int *hchar, int *wcell, int *hcell));

/*
 * Set FSM skew.
 */
__EXTERN int vst_skew __PROTO((int handle, int skew));

/*
 * Get FSM GASCII tables.
 */
__EXTERN void vqt_get_table __PROTO((int handle, short **map));
#if 0 /* old FSMgdos binding */
__EXTERN void	vqt_get_tables __PROTO(( int handle, void **gascii,
					void **style ));
#endif

/*
 * Get FSM cache size
 */
__EXTERN void vqt_cachesize __PROTO((int handle, int which_cache,
                                     size_t *size));
/*
 * Set Character Mapping Mode
 */
__EXTERN void vst_charmap __PROTO((int handle, int mode));

/*
 * Set Kerning Mode
 */
__EXTERN void vst_kern __PROTO((int handle, int tmode, int pmode, int *tracks,
                                int *pairs));

/*
 * Inq Speedo Header
 */
__EXTERN void vqt_fontheader __PROTO((int handle, char *buffer,
                                      char *pathname));

/*
 * Inq track kerning info
 */
__EXTERN void vqt_trackkern __PROTO((int handle, long *x, long *y));

/*
 * Inq pair kerning info
 */
__EXTERN void vqt_pairkern __PROTO((int handle, int ch1, int ch2, long *x,
                                    long *y));

/*
 * bezier curves stuff
 */
__EXTERN void v_set_app_buff __PROTO((void **buf_p, int size));

__EXTERN int v_bez __PROTO((int handle, int count, int *xyarr, char *bezarr,
                            int extent[4], int *npts, int *nmvs));
__EXTERN int v_bez_fill __PROTO((int handle, int count, int *xyarr,
                                 char *bezarr, int extent[4], int *npts,
                                 int *nmvs));
__EXTERN int v_bez_qual __PROTO((int handle, int percent, int *actual));

#ifdef ALTERNATE

/* Use these #defines if you _really_ want to stick to DRI conventions */

__EXTERN int v_bez_con __PROTO((int handle, int onoff));
#define v_bez_on(x) (int)v_bez_con((x), 1)
#define v_bez_off(x) (void)v_bez_con((x), 0)

#else
__EXTERN int v_bez_on __PROTO((int handle));
__EXTERN void v_bez_off __PROTO((int handle));
#endif /* ALTERNATE */

#ifdef __cplusplus
}
#endif

#endif /* _VDIBIND_H */
