/* Unit tests for raster.c */

#include "bitmaps.h"
#include "unit.h"

#include "adler32.h"
#include "global.h"
#include "raster.h"
#include <assert.h>
#include <stdio.h>

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
    drawHorizontalLine(base, 1, 0, 640, SET);

    for (i = 0; i < SCREEN_BUFFER_SIZE; i++) {
        if (i > 19 && i < 40) {
            TEST_ASSERT_EQUAL(~0L, base[i]);
        } else {
            TEST_ASSERT_EQUAL(0, base[i]);
        }
    }
}

u8 count1s(u32 x) {
    u8 count = 0;
    /* This is super inefficient but since we only do it for testing
     * it will have to do */
    while (x) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

u32 arrCount1s(Screen *base, u32 size) {
    u32 count = 0;
    int i = 0;

    for (; i < size; i++)
        count += count1s(base[i]);

    return count;
}

void test_set_pixel() {
    int x = 0;
    int y = 0;

    for (; x < SCREEN_WIDTH; x++) {
        for (; y < SCREEN_HEIGHT / 4; y++) {
            set_pixel(base, x, y, BLACK);

            TEST_ASSERT_EQUAL(arrCount1s(base, SCREEN_BUFFER_SIZE),
                              ((x + 1) * (y + 1)));
        }
    }
}

enum Bool isBlank() {
    int i = 0, sts = True;

    for (; i < SCREEN_BUFFER_SIZE; i++) {
        sts = sts & (base[i] == 0);
    }

    assert(sts == False || sts == True);

    return sts;
}

int main() {
    TEST_BEGIN();

    RUN_TEST(test_black_screen);
    RUN_TEST(test_white_screen);
    RUN_TEST(test_vertical_line);
    RUN_TEST(test_horizontal_line);
    RUN_TEST(test_set_pixel);

    TEST_END();
}
