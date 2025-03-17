/* Unit tests for psg.c and music.c  */

#include "unit.h"

#include "psg.h"
#include "music.h"
#include <osbind.h>
#include <stdio.h>

void setUp() {}
void tearDown() {}


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
    printf("\nValue of mixer: %u\n", read_psg(7));
    set_tone(0, 0x101);
    printf("Value of mixer: %u\n", read_psg(7));
    set_tone(0, 0x1EE);
    printf("Value of channel A fine tone: %u\n", read_psg(0));
    /*
    enable_channel(0, True, True);
    set_volume(0, 11);
    Cconin();

    set_tone(0, 0x1EE);
    enable_channel(0, True, True);
    set_volume(0, 11);
    Cconin();*/

}

void test_update_music() {

}



int main() {
    TEST_BEGIN();

    RUN_TEST(test_write_psg);
    RUN_TEST(test_read_psg);
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
