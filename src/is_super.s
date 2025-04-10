        xdef    _is_supervisor
_is_supervisor:
        move    sr, d0         ; Move status register to D0
        andi.w  #$2000, d0     ; Mask out the supervisor bit (bit 13)
        beq     not_supervisor ; If zero, not in supervisor mode
        moveq   #1, d0         ; Supervisor mode
        rts

not_supervisor:
        moveq   #0, d0         ; Not in supervisor mode
        rts
