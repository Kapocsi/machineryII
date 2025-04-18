/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file psg.h
 * @author Sylvie Mills
 * @brief Defines the music and sound effect processes.
 */

 #ifndef PSG_H
 #define PSG_H

 #include "global.h"

/**Writes the given byte value (0-255) to the given PSG register (0-15). This is a helper
   routine to be used by the other functions in this module.*/
void write_psg(u8 reg, u8 val);

/*Used for testing*/
u8 read_psg(u8 reg);

/*Loads the tone registers (coarse and fine) for the given channel (0=A, 1=B, 2=C) with the
given 12-bit tuning.*/
void set_tone(u8 channel, u32 tuning);

/*Loads the volume register for the given channel.*/
void set_volume(u8 channel, u8 volume);

/*Turns the given channel’s tone/noise signals on/off (0=off, 1=on).*/
void enable_channel(u8 channel, enum Bool tone_on, enum Bool noise_on);

/*Silences all PSG sound production.*/
void stop_sound();

/**Loads the noise register with the given tuning.*/
void set_noise(u8 tuning);

/**Loads the PSG envelope control registers with the given envelope shape
   and 16-bit sustain. */
void set_envelope(u8 shape, u16 sustain);

/**Plays the sound effect for when the swimmer bobs up.*/
void bob_sound();

/**Plays the sound effect for when the player dies.*/
void death_sound();

 #endif
