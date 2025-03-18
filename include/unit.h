#ifndef UNIT_H
#define UNIT_H

#include "global.h"
#include "stdio.h"

/** Setup the testing environment, implemented by the test suite */
void setUp();
/** Tear down the testing environment, implemented by the test suite */
void tearDown();

extern enum Bool silence_tests;

/** @private */
int _runTest(void (*test)());
/** @private */
void _endTest();
/** @private */
void _startTest();
/** @private */
void failTest();

/** Run a test */
#define RUN_TEST(test) (printf("%s:%s:", __FILE__, #test), _runTest(test))

/** Run a test: Expecting it to fail */
#define RUN_FAIL_TEST(test)                                                    \
    (printf("%s:%s:", __FILE__, #test), _runFailTest(test))

#define TEST_ASSERT(cond)                                                      \
    if (!(cond)) {                                                             \
        if (!silence_tests)                                                    \
            printf("\n\tAssertion Failed %s at %s:%d\n", #cond, __FILE__,      \
                   __LINE__);                                                  \
        failTest();                                                            \
    }

#define TEST_ASSERT_EQUAL(value, expected)                                     \
    if (value != expected) {                                                   \
        if (!silence_tests)                                                    \
            printf(                                                            \
                "\n\tAssertion Failed: found 0x%lx expected 0%lx at %s:%d\n",  \
                (unsigned long)value, (unsigned long)expected, __FILE__,       \
                __LINE__);                                                     \
        failTest();                                                            \
    }

#define TEST_BEGIN() _startTest()
#define TEST_END() _endTest();

#endif /* UNIT_H */
