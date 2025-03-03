#ifndef UNIT_H
#define UNIT_H

#include "stdio.h"

/** Setup the testing environment, implemented by the test suite */
void setUp();
/** Tear down the testing environment, implemented by the test suite */
void tearDown();

/** @private */
int _runTest(void (*test)());
/** @private */
void _endTest();
/** @private */
void _startTest();
/** @private */
void failTest();

#define RUN_TEST(test) (printf("%s:%s:", __FILE__, #test), _runTest(test))

#define TEST_ASSERT(cond)                                                      \
    if (!(cond)) {                                                             \
        printf("\n\tAssertion Failed %s at %s:%d\n", #cond, __FILE__,          \
               __LINE__);                                                      \
        failTest();                                                            \
    }

#define TEST_ASSERT_EQUAL(value, expected)                                     \
    if (value != expected) {                                                   \
        printf("\n\tAssertion Failed: found 0x%lx expected 0%lx at %s:%d\n",   \
               (unsigned long)value, (unsigned long)expected, __FILE__,        \
               __LINE__);                                                      \
        failTest();                                                            \
    }

#define TEST_BEGIN() _startTest()
#define TEST_END() _endTest()

#endif /* UNIT_H */
