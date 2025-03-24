/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file psg.h
 * @author Sylvie Mills
 * @brief Defines the music and sound effect processes.
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "global.h"

/**Begins the playing of the song by loading the data for the first note into the PSG */
void start_music();

/**Advances to the next note of the song, as determined by the previous note index */
u8 update_music(u8 prev_index);

#endif