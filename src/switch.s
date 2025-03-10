
; _setBuffer - Set the screen buffer address
;
; Sets the video framebuffer address by updating the Atari ST hardware registers.
; This function should be called with the address of a valid screen buffer.
;
; Parameters:
; - A0: Address of the screen buffer to set.
; Notes:
; - The address must be aligned to a 256-byte boundary.
_setBuffer:
    link    a6,#0
    movem.l d0,-(sp)

    move.l  8(a6),d0               ; Move the passed in address into d0

    ;  clr.b   $ffff820d                ; clear STe extra bit
    lsr.l   #8,d0
    move.b  d0,$ffff8203            ; put in mid screen address byte
    lsr.w   #8,d0
    move.b  d0,$ffff8201            ; put in high screen address byte

    movem.l    (sp)+,d0
    unlk    a6
    rts
    globl   _setBuffer
