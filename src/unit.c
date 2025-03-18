#include "unit.h"
#include "global.h"
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf test_env;
static unsigned long passed_tests = 0;
static unsigned long failed_tests = 0;
enum Bool silence_tests = False;

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
    /* Set the jump back point, if not currently jumping back to this line
     * `setjmp(test_env)` will be 0, otherwise it will be some value set by
     * the jumpee */
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

/** Run test, fail if the test does not fail any of the asserts */
int _runTestFail(void (*test)()) {
    setUp();
    /* Set the jump back point, if not currently jumping back to this line
     * `setjmp(test_env)` will be 0, otherwise it will be some value set by
     * the jumpee */
    if (setjmp(test_env) == 0) {
        /** We don't want print out "assertion failed ...", when we are
         * expecting failure */
        silence_tests = True;
        test();
        printf("Failed\n");
        failed_tests++;
        tearDown();
        silence_tests = False;
        return -1;
    }
    printf("Passed\n");
    passed_tests++;
    silence_tests = False;
    tearDown();
    return 0;
}
