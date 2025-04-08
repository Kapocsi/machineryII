            xdef			_vbl_isr
            xref			_update_music

;----- SUBROUTINE: void vbl_isr() -----
;
; Manages the timing for syncronous events, music, and rendering
;

_vbl_isr:				movem.l			d0-d7/a0-a6,-(sp)


						;jsr			_update_music
						;addq.l			#4,sp



						movem.l			(sp)+,d0-d7/a0-a6
						rte
