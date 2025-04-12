#include <osbind.h>

#include "events.h"
#include "global.h"
#include "input.h"
#include "vector.h"

#define IKBD_STATUS 0xFFFFFC00
#define IKBD_READER 0xFFFFFC02

/** Chars with non obvious ascii mappings, we add them here to that they are
 * placed in 8 bit ascii */
typedef enum { HEADER, DX, DY } MousePacketStage;
static Vector previous_isr;
void keyboardIsr();
static inputState input_state;
MousePacketStage mps = HEADER;

char keyboard[] = "\x80\0331234567890-=\b\t"
                  "qwertyuiop[]\n\x81"
                  "asdfghjkl;'`\x82\\"
                  "zxcvbnm,./\x83\x80\x84 \x85";

char shifted_keyboard[] = "\x80\033!@#$%^&*()_+\b\t"
                          "QWERTYUIOP{}\n\x81"
                          "ASDFGHJKL:\"`\x82\\"
                          "ZXCVBNM<>?\x83\x80\x84 \x85";

char capslocked_keyboard[] = "\x80\0331234567890-=\b\t"
                             "QWERTYUIOP[]\n\x81"
                             "ASDFGHJKL;'`\x82\\"
                             "ZXCVBNM,./\x83\x80\x84 \x85";

#define LSHIFT 0x2a
#define RSHIFT 0x36
#define CAPS_LOCK 0x3a

void handleKeyboard(int c) {
    char *map = keyboard;
    const enum Bool down = !(c & 0x80);
    char input = c & 0x3f;

    /** Handle shift release */
    if (!down && input == LSHIFT || input == RSHIFT) {
        input_state.shift = False;
    }

    /** Only process keydown requests */
    if (!down)
        return;

    switch (c & 0x3f) {
    case RSHIFT:
    case LSHIFT:
        input_state.shift = True;
        break;
    case CAPS_LOCK:
        input_state.capsLock = !input_state.capsLock;
    }

    /** Set the correct scan code -> ascii-ish mapping; todo this mean that
     * symbols won't work in capslock mode, future me problem*/
    if (input_state.capsLock && !input_state.shift)
        map = capslocked_keyboard;
    else if (!input_state.capsLock && input_state.shift)
        map = shifted_keyboard;

    key_press(map[c]);
}

void handleInput() {
    int c = *(char *)IKBD_READER;

    if (mps == HEADER && c != 0xfff8)
        handleKeyboard(c);

    if (c == 0xfff8 && mps != HEADER)
        return;

    switch (mps) {
    case HEADER:
        if (c == 0xfff8)
            mps = DX;
        break;
    case DX:
        mps = DY;
        if (input_state.mouse.x + c > 0 &&
            input_state.mouse.x + c < SCREEN_WIDTH)
            input_state.mouse.x += c;
        break;
    case DY:
        mps = HEADER;
        if (input_state.mouse.y + c > 0 &&
            input_state.mouse.y + c < SCREEN_HEIGHT)
            input_state.mouse.y += c;
    }
}

inputState *initInput() {
    previous_isr = install_vector(70, keyboardIsr);
    return &input_state;
}

void deinitInput() { install_vector(70, previous_isr); }
