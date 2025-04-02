/* Unit tests for words.c  */

#include "unit.h"

#include "words.h"
#include "model.h"
#include <osbind.h>
#include <stdio.h>

#include <time.h>
#include <stdlib.h>


void setUp() {}
void tearDown() {}

void test_text_transfer() {
    int j;
    RowBuffer buffer = {0, 0, {0, 0, 0, 0, 0, 0}, 
    "abcdefghijklmnopqrstuvwxy"};
    Row row = {"1234567891113151719212325", 0};

    next_row(&buffer, &row);

    for (j = 0; j < 25; j++) {
        TEST_ASSERT_EQUAL(j + 0x61, (int) row.text[j]);
    }


}

void test_next_row_cutoff() {
    int j;
    RowBuffer buffer = {1, 5, {0, 0, 0, 0, 0, 0}, 
    "apple apple apple apple a"};
    Row row = {"1234567891113151719212325", 0};

    printf("\nStarting Row: [");
    for (j = 0; j < 25; j++) {
        printf("%c", row.text[j]);
    }
    printf("]\n");

    srand(time(NULL));
    next_row(&buffer, &row);

    printf("\nNext Row: [");
    for (j = 0; j < 25; j++) {
        printf("%c", row.text[j]);
    }
    printf("]\n");

    next_row(&buffer, &row);

    printf("\nNext Row: [");
    for (j = 0; j < 25; j++) {
        printf("%c", row.text[j]);
    }
    printf("]\n");

    next_row(&buffer, &row);

    printf("\nNext Row: [");
    for (j = 0; j < 25; j++) {
        printf("%c", row.text[j]);
    }
    printf("]\n");
}


int main() {
    TEST_BEGIN();

    RUN_TEST(test_text_transfer);
    RUN_TEST(test_next_row_cutoff);

    TEST_END();
}
