/* Unit tests for psg.c and music.c  */

#include "unit.h"

#include "global.h"
#include "psg.h"
#include "music.h"
#include <osbind.h>
#include <stdio.h>

static const u32 melody[] = {0x0F0, 0x0BE, 0x0A0, 0x0AA};

void setUp() {}
void tearDown() {}

u32 tickSinceInception() {
    long ssp = Super(0);
    u32 ticks = *(u32 *)(0x462);
    Super(ssp);

    return ticks;
}


void test_write_read_psg() {
    write_psg(0, 0xFE);
    TEST_ASSERT_EQUAL(0xFE, read_psg(0));
    write_psg(0, 0x01);
    TEST_ASSERT_EQUAL(0x1, read_psg(0));

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
}

void test_update_music() {
    u32 ticks = tickSinceInception();
    u32 ticksElapsed;
    u8 prev_index = 0;
    u32 i;
    
    start_music();

    for (i = 0; i < 50; i++) {
        while (tickSinceInception() - ticks < 20)
            ;

        printf("Last note: %lu\n", (u32) prev_index);
        prev_index = update_music(prev_index);
        ticks = tickSinceInception();
    }
}



int main() {
    TEST_BEGIN();

    RUN_TEST(test_write_read_psg);
    RUN_TEST(test_set_tone);
    RUN_TEST(test_set_volume);
    RUN_TEST(test_enable_channel);
    RUN_TEST(test_stop_sound);
    RUN_TEST(test_set_noise);
    RUN_TEST(test_set_envelope);
    RUN_TEST(test_start_music);
    RUN_TEST(test_update_music);

    TEST_END();
}
