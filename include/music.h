/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file psg.h
 * @author Sylvie Mills
 * @brief Defines the music and sound effect processes.
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "global.h"

static const u32 melody[] = {0x1E0, 0x17D, 0x140, 0x17D};

/**Begins the playing of the song by loading the data for the first note into the PSG */
void start_music();

/**Advances to the next note of the song, as determined by the amount of time elapsed
   since the previous call */
void update_music(u32 time_elapsed);

#endif
