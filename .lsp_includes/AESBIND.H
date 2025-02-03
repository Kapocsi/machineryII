#ifndef _AESBIND_H
#define _AESBIND_H

#include <gemfast.h>
#ifndef _COMPILER_H
#include <compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

__EXTERN int appl_init __PROTO((void));
__EXTERN int appl_read __PROTO((int ApId, int Length, void *ApPbuff));
__EXTERN int appl_write __PROTO((int ApId, int Length, void *ApPbuff));
__EXTERN int appl_find __PROTO((const char *Name));
__EXTERN int appl_tplay __PROTO((void *Mem, int Num, int Scale));
__EXTERN int appl_trecord __PROTO((void *Mem, int Count));
__EXTERN int appl_exit __PROTO((void));
__EXTERN int evnt_keybd __PROTO((void));
__EXTERN int evnt_button __PROTO((int Clicks, int WhichButton, int WhichState,
                                  int *Mx, int *My, int *ButtonState,
                                  int *KeyState));
__EXTERN int evnt_mouse __PROTO((int EnterExit, int InX, int InY, int InW,
                                 int InH, int *OutX, int *OutY,
                                 int *ButtonState, int *KeyState));
__EXTERN int evnt_mesag __PROTO((int MesagBuf[]));
__EXTERN int evnt_timer __PROTO((unsigned long Interval));
#ifdef __OLD_WAY__
__EXTERN int evnt_multi __PROTO(
    (int Type, int Clicks, int WhichButton, int WhichState, int EnterExit1,
     int In1X, int In1Y, int In1W, int In1H, int EnterExit2, int In2X, int In2Y,
     int In2W, int In2H, int MesagBuf[], unsigned int I1, unsigned int I2,
     int *OutX, int *OutY, int *ButtonState, int *KeyState, int *Key,
     int *ReturnCount));
#else
__EXTERN int evnt_multi __PROTO(
    (int Type, int Clicks, int WhichButton, int WhichState, int EnterExit1,
     int In1X, int In1Y, int In1W, int In1H, int EnterExit2, int In2X, int In2Y,
     int In2W, int In2H, int MesagBuf[], unsigned long Interval, int *OutX,
     int *OutY, int *ButtonState, int *KeyState, int *Key, int *ReturnCount));
#endif /* __OLD_WAY__ */
__EXTERN int evnt_dclick __PROTO((int ToSet, int SetGet));

__EXTERN int form_do __PROTO((void *Tree, int StartObj));
__EXTERN int form_dial __PROTO((int Flag, int Sx, int Sy, int Sw, int Sh,
                                int Bx, int By, int Bw, int Bh));
__EXTERN int form_alert __PROTO((int DefButton, char *Str));
__EXTERN int form_error __PROTO((int ErrorCode));
__EXTERN int form_center __PROTO((void *Tree, int *Cx, int *Cy, int *Cw,
                                  int *Ch));
__EXTERN int form_keybd __PROTO((void *Ktree, int Kobject, int Kobnext,
                                 int Kchar, int *Knxtobject, int *Knxtchar));
__EXTERN int form_button __PROTO((void *Btree, int Bobject, int Bclicks,
                                  int *Bnxtobj));

__EXTERN int fsel_input __PROTO((char *Path, char *File, int *ExitButton));
__EXTERN int fsel_exinput __PROTO((char *Path, char *File, int *ExitButton,
                                   char *Prompt));

__EXTERN int graf_rubberbox __PROTO((int Ix, int Iy, int Iw, int Ih, int *Fw,
                                     int *Fh));
__EXTERN int graf_dragbox __PROTO((int Sw, int Sh, int Sx, int Sy, int Bx,
                                   int By, int Bw, int Bh, int *Fw, int *Fh));
__EXTERN int graf_movebox __PROTO((int Sw, int Sh, int Sx, int Sy, int Dx,
                                   int Dy));
__EXTERN int graf_growbox __PROTO((int Sx, int Sy, int Sw, int Sh, int Fx,
                                   int Fy, int Fw, int Fh));
__EXTERN int graf_shrinkbox __PROTO((int Fx, int Fy, int Fw, int Fh, int Sx,
                                     int Sy, int Sw, int Sh));
__EXTERN int graf_watchbox __PROTO((void *Tree, int Object, int InState,
                                    int OutState));
__EXTERN int graf_slidebox __PROTO((void *Tree, int Parent, int Object,
                                    int Direction));
__EXTERN int graf_handle __PROTO((int *Wchar, int *Hchar, int *Wbox,
                                  int *Hbox));
__EXTERN int graf_mouse __PROTO((int Form, void *FormAddress));
__EXTERN int graf_mkstate __PROTO((int *Mx, int *My, int *ButtonState,
                                   int *KeyState));

__EXTERN int menu_bar __PROTO((void *Tree, int ShowFlag));
__EXTERN int menu_icheck __PROTO((void *Tree, int Item, int CheckFlag));
__EXTERN int menu_ienable __PROTO((void *Tree, int Item, int EnableFlag));
__EXTERN int menu_tnormal __PROTO((void *Tree, int Item, int NormalFlag));
__EXTERN int menu_text __PROTO((void *Tree, int Item, char *Text));
__EXTERN int menu_register __PROTO((int ApId, char *MenuText));
__EXTERN int menu_popup __PROTO((MENU_T * me_menu, int me_xpos, int me_ypos,
                                 MENU_T *me_mdata));
__EXTERN int menu_attach __PROTO((int me_flag, OBJECT *me_tree, int me_item,
                                  MENU_T *me_mdata));
__EXTERN int menu_istart __PROTO((int me_flag, OBJECT *me_tree, int me_imenu,
                                  int me_item));
__EXTERN int menu_settings __PROTO((int me_flag, MN_SET *me_values));

__EXTERN int objc_add __PROTO((void *Tree, int Parent, int Child));
__EXTERN int objc_delete __PROTO((void *Tree, int Object));
__EXTERN int objc_draw __PROTO((void *Tree, int Start, int Depth, int Cx,
                                int Cy, int Cw, int Ch));
__EXTERN int objc_find __PROTO((void *Tree, int Start, int Depth, int Mx,
                                int My));
__EXTERN int objc_offset __PROTO((void *Tree, int Object, int *X, int *Y));
__EXTERN int objc_order __PROTO((void *Tree, int Object, int NewPos));
#ifdef __TCC_GEMLIB__
__EXTERN int objc_edit __PROTO((void *Tree, int Object, int Char, int *Index,
                                int Kind));
#else
__EXTERN int objc_edit __PROTO((void *Tree, int Object, int Char, int Index,
                                int Kind, int *NewIndex));
#endif
__EXTERN int objc_change __PROTO((void *Tree, int Object, int Res, int Cx,
                                  int Cy, int Cw, int Ch, int NewState,
                                  int Redraw));

__EXTERN int rsrc_load __PROTO((char *Name));
__EXTERN int rsrc_free __PROTO((void));
__EXTERN int rsrc_gaddr __PROTO((int Type, int Index, void *Address));
__EXTERN int rsrc_saddr __PROTO((int Type, int Index, void *Address));
__EXTERN int rsrc_obfix __PROTO((void *Tree, int Index));

__EXTERN int scrp_read __PROTO((char *Scrappath));
__EXTERN int scrp_write __PROTO((char *Scrappath));
#if 0
/* not present in GEM V<2 */
__EXTERN int	scrp_clear __PROTO((void));
#endif

__EXTERN int shel_read __PROTO((char *Command, char *Tail));
__EXTERN int shel_write __PROTO((int Exit, int Graphic, int Aes, char *Command,
                                 char *Tail));
__EXTERN int shel_find __PROTO((char *buf));
__EXTERN int shel_envrn __PROTO((char *result, char *param));
__EXTERN int shel_get __PROTO((char *Buf, int Len));
__EXTERN int shel_put __PROTO((char *Buf, int Len));

__EXTERN int wind_create __PROTO((int Parts, int Wx, int Wy, int Ww, int Wh));
__EXTERN int wind_open __PROTO((int WindowHandle, int Wx, int Wy, int Ww,
                                int Wh));
__EXTERN int wind_close __PROTO((int WindowHandle));
__EXTERN int wind_delete __PROTO((int WindowHandle));
#ifdef __TCC_GEMLIB__
__EXTERN int wind_get __PROTO((int WindowHandle, int What, ...));
#else
__EXTERN int wind_get __PROTO((int WindowHandle, int What, int *W1, int *W2,
                               int *W3, int *W4));
#endif
__EXTERN int wind_set __PROTO((int WindowHandle, int What, ...));
__EXTERN int wind_find __PROTO((int X, int Y));
__EXTERN int wind_update __PROTO((int Code));
__EXTERN int wind_calc __PROTO((int Type, int Parts, int InX, int InY, int InW,
                                int InH, int *OutX, int *OutY, int *OutW,
                                int *OutH));
__EXTERN void wind_new __PROTO((void));

__EXTERN int rc_copy __PROTO((GRECT * src, GRECT *dst));
__EXTERN int rc_equal __PROTO((GRECT * src, GRECT *dst));
__EXTERN int rc_intersect __PROTO((GRECT * r1, GRECT *r2));
__EXTERN int *grect_to_array __PROTO((GRECT * area, int *array));

#ifdef __cplusplus
}
#endif

#endif /* _AESBIND_H */
