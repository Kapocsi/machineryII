#include "lib/unity.h"
#include "lib/unity_i.h"

#include "global.h"
#include "raster.h"

Screen base[SCREEN_BUFFER_SIZE];

void setUp() {
    int i = 0;

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++)
        base[i] = 0;
}
void tearDown() {}

void test_black_screen() {
    int i = 0;
    black_screen(base);

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++)
        TEST_ASSERT_EQUAL(-1, base[i]);
}

void test_white_screen() {
    int i = 0;
    black_screen(base);
    white_screen(base);

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++)
        TEST_ASSERT_EQUAL(0, base[i]);
}

void test_vertical_line() {
    int i = 0;
    white_screen(base);
    drawVerticalLine(base, 1, 0, 400);

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        if (i % 20 == 0) {
            TEST_ASSERT_EQUAL(0x40000000, base[i]);
        } else {
            TEST_ASSERT_EQUAL(0, base[i]);
        }
    }
        
}

void test_horizontal_line() {
    int i = 0;
    white_screen(base);
    drawHorizontalLine(base, 1, 0, 640);

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        if (i > 19 && i < 40) {
            TEST_ASSERT_EQUAL(~0L, base[i]);
        } else {
            TEST_ASSERT_EQUAL(0, base[i]);
        }
    }
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_black_screen);
    RUN_TEST(test_white_screen);
    RUN_TEST(test_vertical_line);
    RUN_TEST(test_horizontal_line);

    UNITY_END();
}
