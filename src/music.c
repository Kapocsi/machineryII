#include "global.h"
#include "music.h"
#include "psg.h"
#include <stdio.h>

/**The current index in the SIXTEENTHS array in music.c */
u8 current_beat; 

/**The current index in the MELODY array in music.c */
u8 current_note;

/**The number of ticks since the last sixteenth */
u8 counter;

static const u16 MELODY[] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,

    0x475, 0, 0x1, 0x475, 
    0, 0x01, 0x475, 0, 
    0x01, 0, 0x357, 0, 
    0x475, 0, 0x357, 0,

    0x475, 0, 0x01, 0x475, 
    0, 0x01, 0x475, 0, 
    0x01, 0, 0x357, 0, 
    0x475, 0, 0x357, 0,

    0x475, 0, 0x01, 0x475, 
    0, 0x01, 0x475, 0, 
    0x01, 0, 0x327, 0, 
    0x475, 0, 0x327, 0,

    0x475, 0, 0x01, 0x475, 
    0x01, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0,

    0, 0, 0, 0, 
    0, 0, 0, 0,
    0x1FC, 0, 0, 0,
    0, 0, 0, 0,

    0x2FA, 0, 0, 0,
    0, 0, 0, 0,
    0, 0x1, 0, 0,
    0, 0, 0, 0,

    0x2FA, 0x1, 0x2FA, 0x1};

static const enum Bool SIXTEENTHS[] = {
    True, False, False, True,
    True, False, True, False,
    False, True, True, False,
    True, False, False, False, 
    True, False, False, True,
    True, False, True, False,
    False, True, True, False,
    True, False, True, False};

void start_music() {
    current_beat = 0;
    current_note = 0;

    set_tone(0, MELODY[0]);
    write_psg(0x7, 0xEE);
    set_volume(0, 14);
    set_volume(1, 0x10);

    set_noise(0x1F);
    write_psg(0xC, 0x02);/*0x38 to get explosion*/
    write_psg(0xD, 0);
}

void update_music() {
    enum Bool beat_value;
    u16 note_value;

    if (counter < 10) {
        current_beat = (current_beat + 1) & 0x1F;
        beat_value = SIXTEENTHS[(current_beat + 1) & 0x1F];

        current_note = (current_note + 1) & 0x7F;
        note_value = MELODY[(current_note + 1) & 0x7F];

        if (beat_value) {
            set_noise(0x1F);
            write_psg(0xC, 0x02);
            write_psg(0xD, 0);
        }
        if (note_value != 0) {
            set_tone(0, note_value);
        }

        counter = 0;

    } else {
        counter++;
    }
}

