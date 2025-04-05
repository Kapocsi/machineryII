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

void test_next_row_cutoff() {
    int i;
    int j;
    RowBuffer buffer = {0, 0, {0, 0, 0, 0, 0, 0}, ""};
    Row row = {"testtesttesttesttesttestt", 0};

    printf("\n\nStarting Row: [");
    for (j = 0; j < 25; j++) {
        printf("%c", row.text[j]);
    }
    printf("]\n");

    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        new_row(&buffer);
        change_row(&row, buffer.string);

        printf("\nNext Row: [");
        for (j = 0; j < 25; j++) {
            printf("%c", row.text[j]);
        }
        printf("]\n");
    }
}


int main() {
    TEST_BEGIN();

    RUN_TEST(test_next_row_cutoff);

    TEST_END();
}
