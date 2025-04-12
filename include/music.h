/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file psg.h
 * @author Sylvie Mills
 * @brief Defines the music and sound effect processes.
 */

#ifndef MUSIC_H
#define MUSIC_H

/**Begins the playing of the song by loading the data for the first note into
 * the PSG */
void start_music();

/**Advances to the next note and drum beat, and plays their sound. It should be
  run every 10 ticks.*/
void update_music();

#endif
