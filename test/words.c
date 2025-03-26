/* Unit tests for words.c  */

#include "unit.h"

#include "words.h"
#include <osbind.h>
#include <stdio.h>


void setUp() {}
void tearDown() {}


void test_insert_cutoff() {
    RowBuffer buffer;
    TEST_ASSERT_EQUAL(0x1, 0);
}


int main() {
    TEST_BEGIN();

    RUN_TEST(test_insert_cutoff);

    TEST_END();
}
