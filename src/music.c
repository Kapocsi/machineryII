#include "music.h"
#include "psg.h"

static const u32 melody[] = {0x0F0, 0x0BE, 0x0A0, 0x0BE};

void start_music() {
    set_tone(0, melody[0]);
    enable_channel(0, True, True);
    set_volume(0, 11);
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