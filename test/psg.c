/* Unit tests for psg.c and music.c  */

#include "unit.h"

#include "psg.h"
#include "music.h"
#include <osbind.h>
#include <stdio.h>

void setUp() {}
void tearDown() {}

u32 tickSinceInception() {
    long ssp = Super(0);
    u32 ticks = *(u32 *)(0x462);
    Super(ssp);

    return ticks;
}

void test_write_psg() {

}

void test_read_psg() {
    write_psg(0, 0xFE);
    printf("\nValue of A fine tone: %u\n", read_psg(0));
}

void test_set_tone() {

}

void test_set_volume() {

}

void test_enable_channel() {

}

void test_stop_sound() {

}

void test_set_noise() {

}

void test_set_envelope() {

}

void test_start_music() {
    start_music();
    printf("\nValue of channel A fine tone: %x\n", read_psg(0));
    printf("Value of mixer: %x\n", read_psg(7));   

}

void test_update_music() {

}



int main() {
    int i = 0;
    u32 ticks;
    u8 tick_count = 0;
    MusicModel music_model = {0, 0};

    printf("\n");
    TEST_BEGIN();

    start_music();
    ticks = tickSinceInception();

    for (i = 0; i < 1000; i++) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();

        if (tick_count >= 10) {
            update_music(&music_model);
            tick_count = 0;
        } else {
            tick_count++;
        }
    }
    stop_sound();

    /*
    set_noise(0x1F);
    enable_channel(0, True, True);
    set_volume(0, 0x10);
    write_psg(0xC, 0x02);
    write_psg(0xD, 0);*/


    

    /*
    RUN_TEST(test_write_read_psg);
    RUN_TEST(test_set_tone);
    RUN_TEST(test_set_volume);
    RUN_TEST(test_enable_channel);
    RUN_TEST(test_stop_sound);
    RUN_TEST(test_set_noise);
    RUN_TEST(test_set_envelope);
    RUN_TEST(test_start_music);
    RUN_TEST(test_update_music);*/

    TEST_END();
}
