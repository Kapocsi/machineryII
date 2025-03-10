    .xdef _keyboardIsr
    .xref _handleInput

.equ MFP_IN_SERVICE_B_REG,0xFFFFFA11
.equ IKBD_RDR_REG,0xFFFFFC02
.equ IKBD_STATUS_REG,0xFFFFFC00

_keyboardIsr:
    movem.l	d0-d7/a0-a6,-(sp)

    movea.l	#IKBD_STATUS_REG,a0
    btst.b  #0,(a0)
    beq		IKBD_RETURN

    ; clr.l	d0
    ; movea.l	#IKBD_RDR_REG,a2
    ; move.b	(a2),d0

    jsr _handleInput


IKBD_RETURN:
	andi.b	#0xBF,MFP_IN_SERVICE_B_REG
    movem.l	(sp)+,d0-d7/a0-a6
	rte

