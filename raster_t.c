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

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_black_screen);
    RUN_TEST(test_white_screen);

    UNITY_END();
}
