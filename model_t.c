/* Unit tests for model.c */

#include "bitmap.h"
#include "lib/unity.h"
#include "lib/unity_i.h"

#include "model.h"

BitMap sprites[37];
Character characters[4];

void setUp() {}
void tearDown() {}

void test_bob_up() {
    Swimmer swimmer = {200, 200, 0, sprites};
    bob_up(&swimmer);
    TEST_ASSERT_EQUAL(190, swimmer.y);
}

void test_sink() {
    Swimmer swimmer = {200, 200, 0, sprites};
    sink(&swimmer);
    TEST_ASSERT_EQUAL(201, swimmer.y);
}

void test_switch_sprite() {
    Swimmer swimmer = {200, 200, 0, sprites};
    switch_sprite(&swimmer);
    TEST_ASSERT_EQUAL(1, swimmer.sprite);
    switch_sprite(&swimmer);
    TEST_ASSERT_EQUAL(0, swimmer.sprite);
}

void test_set_char () {
    Character character = {200, 200, 1, sprites};
    set_char(&character, 2);
    TEST_ASSERT_EQUAL(2, character.sprite);
}

void test_shift_pointer () {
    u8 i;
    Pointer pointer = {100, 100, 200, 10, 0};
    for (i = 0; i < 15; i++) {
        TEST_ASSERT_EQUAL(i, pointer.char_pos);
        TEST_ASSERT_EQUAL(100 + i * 10, pointer.x);
        shift_pointer(&pointer);
    }
    TEST_ASSERT_EQUAL(0, pointer.char_pos);
    TEST_ASSERT_EQUAL(100, pointer.x);
}

void test_increase_counter () {
    Counter counter = {200, 200, 999};
    increase_counter(&counter);
    TEST_ASSERT_EQUAL(1000, counter.value);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_bob_up);
    RUN_TEST(test_sink);
    RUN_TEST(test_switch_sprite);
    RUN_TEST(test_set_char);
    RUN_TEST(test_shift_pointer);
    RUN_TEST(test_increase_counter);

    UNITY_END();
}
