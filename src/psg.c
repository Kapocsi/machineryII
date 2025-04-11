#include "psg.h"
#include "super.h"

void write_psg(u8 reg, u8 val) {
    volatile u8 *reg_select = (u8 *)0xFFFF8800;
    volatile u8 *reg_write = (u8 *)0xFFFF8802;
    u32 old_ssp;

    if (reg <= 15) {
        SuperDo({
            *reg_select = reg;
            *reg_write = val;
        });
    }
}

u8 read_psg(u8 reg) {
    volatile u8 *reg_read = (u8 *)0xFFFF8800;
    u32 old_ssp;
    u8 value = 0;

    if (reg <= 15) {
        SuperDo({
            *reg_read = reg;
            value = *reg_read;
        });
    }
    return value;
}

void set_tone(u8 channel, u32 tuning) {
    if (channel <= 2) {
        write_psg(channel << 1, tuning & 0x0FF);
        write_psg((channel << 1) + 1, tuning >> 8);
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

void stop_sound() { write_psg(7, 0xFF); }

void set_noise(u8 tuning) { write_psg(6, tuning & 0x1F); }

void set_envelope(u8 shape, u16 sustain) {}

void bob_sound() {
    u16 i = 0;
    write_psg(0x7, 0xEA);
    set_tone(2, 0x1D6);
    set_volume(2, 12);

    while (i < 7500) {
        i++;
    }
    i = 0;
    set_tone(2, 0x1AA);

    while (i < 7500) {
        i++;
    }
    write_psg(0x7, 0xEE);
}

void death_sound() {
    write_psg(0x7, 0xCE);
    set_noise(0x03);
    set_volume(2, 0x10);
    write_psg(0xC, 0x11);
    write_psg(0xD, 0);
}
