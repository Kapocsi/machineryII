/* Unit tests for psg.c and music.c  */

#include "unit.h"

#include "music.h"
#include "psg.h"
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

void test_write_read_psg() {
    write_psg(0, 0xFE);
    TEST_ASSERT_EQUAL(0xFE, read_psg(0));
    write_psg(0, 0x01);
    TEST_ASSERT_EQUAL(0x01, read_psg(0));
}

void test_start_music() {
    start_music();
    printf("\nValue of channel A fine tone: %x\n", read_psg(0));
    printf("Value of mixer: %x\n", read_psg(7));

    printf("Press a key to continue\n");
    while (!Cconis())
        ;

    Cnecin();
}

void test_update_music() {
    int i = 0;
    u32 ticks;
    u8 tick_count = 0;

    start_music();
    ticks = tickSinceInception();

    printf("\nPress a key to continue\n");
    while (!Cconis()) {
        while (tickSinceInception() - ticks < 1)
            ;

        ticks = tickSinceInception();
        update_music();
    }
    stop_sound();
    Cnecin();
}

void test_bob_sound() {
    printf("\nBob Sound\n");
    bob_sound();
    while (!Cconis())
        ;

    Cnecin();
    printf("Press a key to continue\n");
}

void test_death_sound() {
    printf("\nDeath Sound\n");
    death_sound();
    while (!Cconis())
        ;

    Cnecin();
    printf("Press a key to continue\n");
}

int main() {

    TEST_BEGIN();

    RUN_TEST(test_write_read_psg);
    RUN_TEST(test_start_music);
    RUN_TEST(test_update_music);
    RUN_TEST(test_bob_sound);
    RUN_TEST(test_death_sound);

    TEST_END();
}
