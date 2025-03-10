#include "font.h"
#include "adler32.h"
#include "global.h"
#include "raster.h"
#include "unit.h"

#include <string.h>

Screen base[SCREEN_BUFFER_SIZE];

void setUp() { white_screen(base); }
void tearDown() {}

void testSmallText() {
    char *text = "Hello World!";
    u32 hash;

    drawSmallText(base, text, 0, 0, SET);
    hash = adler32((u8 *)base, SCREEN_BUFFER_SIZE * 4);

    /** Known correct hash*/
    TEST_ASSERT_EQUAL(hash, 0x226c1291);
}

void testBigText() {
    char *text = "Hello World!";
    u32 hash;

    drawBigText(base, text, 0, 0, SET);
    hash = adler32((u8 *)base, SCREEN_BUFFER_SIZE * 4);

    /** Known correct hash*/
    TEST_ASSERT_EQUAL(hash, 0x684bb3db);
}

int main() {
    TEST_BEGIN();

    RUN_TEST(testSmallText);
    RUN_TEST(testBigText);

    TEST_END();
}
