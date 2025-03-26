#include "psg.h"

void write_psg(u8 reg, u8 val) {
    volatile u8 *reg_select = (u8 *) 0xFFFF8800;
	volatile u8 *reg_write = (u8 *) 0xFFFF8802;
    u32 old_ssp;

    if (reg <= 15) {
        old_ssp = Super(0);
        *reg_select = reg;
        *reg_write  = val;
        Super(old_ssp);
    }
}

u8 read_psg(u8 reg) {
    volatile u8 *reg_select = (u8 *) 0xFFFF8800;
	volatile u8 *reg_read = (u8 *) 0xFFFF8802;
    u32 old_ssp;
    u8 value = 0;

    if (reg <= 15) {
        old_ssp = Super(0);
        *reg_select = reg;
        value = *reg_read;
        Super(old_ssp);
    }
    return value;
}

void set_tone(u8 channel, u32 tuning) {
    if (channel <= 2) {
        write_psg(channel << 1, tuning & 0xFF);
        write_psg((channel << 1) + 1, tuning & 0xF00);
    }
}

void set_volume(u8 channel, u8 volume) {
    if (channel <= 2)
        write_psg(channel + 8, volume & 0x1F);
}

void enable_channel(u8 channel, enum Bool tone_on, enum Bool noise_on) {
    if (channel <= 2) {
        write_psg(7, (~tone_on << channel) + (~noise_on << (channel + 3)));
    }
}

void stop_sound() {
    write_psg(7, 0x3F);
}

void set_noise(u8 tuning) {
    write_psg(6, tuning & 0x1F);
}

void set_envelope(u8 shape, u16 sustain) {

}
