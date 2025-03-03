#include "adler32.h"
#include "font.h"
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

    drawSmallText(base, text, strlen(text), 0, 0, SET);
    hash = adler32((u8 *)base, SCREEN_BUFFER_SIZE * 4);

    /** Known correct hash*/
    TEST_ASSERT_EQUAL(hash, 0x64070cd9l);
}

void testBigText() {
    char *text = "Hello World!";
    u32 hash;

    drawBigText(base, text, strlen(text), 0, 0, SET);
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
