#include "music.h"
#include "psg.h"

static const u16 melody[] = {0x0F0, 0x0BE, 0x0A0, 0x0BE};
static const u8 beat[] = {0x09, 0x03, 0x06, 0x01};

void start_music() {
    set_tone(0, melody[0]);
    write_psg(0x7, 0xEE);
    set_volume(0, 12);
    set_volume(1, 0x10);
}

u8 update_music(u8 prev_index) {
    if (prev_index < 3) {
        set_tone(0, melody[prev_index + 1]);
        return (u8) (prev_index + 1);

    } else {
        set_tone(0, melody[0]);
        return 0;
    }
}

u8 update_beat(u8 prev_index, u8 quarter) {
    set_noise(0x1F);
    write_psg(0xC, 0x02);
    write_psg(0xD, 0);
    /*if (beat[prev_index] & (1 << quarter)) {
        set_noise(0x1F);
        write_psg(0xC, 0x02);
        write_psg(0xD, 0);
    }

    if (prev_index < 3) 
        return (u8) (prev_index + 1);
    else*/
    return 0;
}