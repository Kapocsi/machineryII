#include "unit.h"
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf test_env;
static unsigned long passed_tests = 0;
static unsigned long failed_tests = 0;

/** Reset the testing environment */
void _startTest() {
    passed_tests = 0;
    failed_tests = 0;
    printf("%ld %ld \n", passed_tests, failed_tests);
    printf("====== BEGIN TESTS ===== \n");
}

/** End the testing and print out final stats */
void _endTest() {
    printf("======= END TESTS ======= \n"
           "%lu tests run, %lu passing, %lu failing.\n",
           passed_tests + failed_tests, passed_tests, failed_tests);
    if (passed_tests == passed_tests + failed_tests)
        exit(0);
    exit(-1);
}

void failTest() { longjmp(test_env, 1); }

/** Run test and save results to global pass/fail counts */
int _runTest(void (*test)()) {
    setUp();
    if (setjmp(test_env) == 0) {
        test();
        printf("Passed\n");
        passed_tests++;
        tearDown();
        return 0;
    }
    printf("Failed\n");
    failed_tests++;
    tearDown();
    return -1;
}
