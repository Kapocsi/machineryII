/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file psg.h
 * @author Sylvie Mills
 * @brief Defines the music and sound effect processes.
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "global.h"

/**
 * @struct MusicModel
 * @brief Stores the current music and rhythm data.
 * Stores note array index (for the melody) and a beat array index (like a
 * beat of a drum, not a rhythmic beat)
 */
 typedef struct {
   u8 current_beat;  /**The current index in the SIXTEENTHS array in music.c */
   u8 current_note;  /**The current index in the MELODY array in music.c */
} MusicModel;

/**Begins the playing of the song by loading the data for the first note into the PSG */
void start_music();

/**Advances to the next note and drum beat, and plays their sound. It should be run every
  10 ticks.*/
void update_music(MusicModel *model);

#endif
