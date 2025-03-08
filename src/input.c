#include <osbind.h>
#include <stdio.h>

#include "global.h"
#include "input.h"

#define IKBD_STATUS 0xFFFFFC00
#define IKBD_READER 0xFFFFFC02

/** Ascii-ish indexed bit array */
static long held_keys[8];

/** Chars with non obvious ascii mappings, we add them here to that they are
 * placed in 8 bit ascii */
typedef enum { UNDEF = 0x80, CTRL, LSHIFT, RSHIFT, ALT, CAPS_LOCK } CTRL_CHARS;
typedef enum { HEADER, DX, DY } MousePacketStage;

static Vector previous_isr;

MousePacketStage mps = HEADER;
int x = 0;
int y = 0;
void keyboardIsr();

Vector install_vector(int num, Vector vector) {
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);

    orig = *vectp;
    *vectp = vector;

    Super(old_ssp);
    return orig;
}

char keyboard[] = "\x80\0331234567890-=\b\t"
                  "qwertyuiop[]\n\x81"
                  "asdfghjkl;'`\x82\\"
                  "zxcvbnm,./\x83\x80\x84 \x85";

char shifted_keyboard[] = "\x80\033!@#$%^&*()_+\b\t"
                          "QWERTYUIOP{}\n\x81"
                          "ASDFGHJKL:\"`\x82\\"
                          "ZXCVBNM<>?\x83\x80\x84 \x85";

char capslocked_keyboard[] = "\x80\0331234567890-=\b\t"
                             "qwertyuiop[]\n\x81"
                             "asdfghjkl;'`\x82\\"
                             "zxcvbnm,./\x83\x80\x84 \x85";

void handleInput() {
    int c = *(char *)IKBD_READER;

    if (c == 0xfff8 && mps != HEADER)
        return;

    switch (mps) {
    case HEADER:
        if (c == 0xfff8)
            mps = DX;
        break;
    case DX:
        mps = DY;
        if (x + c > 0 && x + c < SCREEN_WIDTH)
            x += c;
        break;
    case DY:
        mps = HEADER;
        if (y + c > 0 && y + c < SCREEN_HEIGHT)
            y += c;
    }

    /* printf("%d %d %d\n", mps, x, y); */
}

void initInput() { previous_isr = install_vector(70, keyboardIsr); }
void deinitInput() { install_vector(70, previous_isr); }
