#include "lib/unity.h"
#include "lib/unity_i.h"

#include "bitmaps.h"

void setUp() {}
void tearDown() {}

void testBitMapDeclaration() {
    int i = 0;

    TEST_ASSERT(BlackBox.width == 32);
    TEST_ASSERT(BlackBox.height == 32);

    for (i = 0; i < 32; i++) {
        TEST_ASSERT(BlackBox.longs[i] == ~0);
    }
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(testBitMapDeclaration);

    UNITY_END();
}
