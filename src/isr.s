    xdef _keyboardIsr
    xref _handleInput

    MFP_IN_SERVICE_B_REG	equ		$FFFFFA11
    IKBD_RDR_REG			equ		$FFFFFC02
    IKBD_STATUS_REG		    equ		$FFFFFC00

_keyboardIsr:
    movem.l	d0-d7/a0-a6,-(sp)

startRead:

    movea.l	#IKBD_STATUS_REG,a0
    btst.b  #0,(a0)
    beq		IKBD_RETURN

    jsr     _handleInput

    bra     startRead


IKBD_RETURN:
	andi.b	#$BF,MFP_IN_SERVICE_B_REG
    movem.l	(sp)+,d0-d7/a0-a6
	rte

