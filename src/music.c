#include "music.h"
#include "psg.h"

void start_music() {
    set_tone(0, melody[0]);
    set_volume(0, 11);
    enable_channel(0, True, True);
}

/**Advances to the next note of the song, as determined by the amount of time elapsed
   since the previous call */
void update_music(u32 time_elapsed) {
    set_tone(0, melody[time_elapsed >> 2]);
}