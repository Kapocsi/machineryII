/* Unit tests for words.c  */

#include "unit.h"

#include "words.h"
#include "model.h"
#include <osbind.h>
#include <stdio.h>


void setUp() {}
void tearDown() {}


void test_text_transfer() {
    int j;
    char* base_string;
    RowBuffer buffer = {0, 0, {0, 0, 0, 0, 0, 0}, 
    "aaaaaaaaaaaaaaaaaaaaaaaaa"};
    Row row = {"abcdefghijklmnopqrstuvwxy", 0};

    next_row(&buffer, &row);

    for (j = 0; j < 25; j++) {
        TEST_ASSERT_EQUAL('a', row.text[j]);
    }

}

void test_next_row_cutoff() {
    RowBuffer buffer = {2, 5, {0, 0, 0, 0, 0, 0}, 
    "pple apple apple apple ap"};
    Row row = {"1234567891113151719212325", 0};

    next_row(&buffer, &row);
    next_row(&buffer, &row);

}


int main() {
    TEST_BEGIN();

    RUN_TEST(test_text_transfer);
    RUN_TEST(test_next_row_cutoff);

    TEST_END();
}
