/* Unit tests for model.c and events.c  */

#include "unit.h"

#include "events.h"

#define TEXT "the quick brown"
static const char new_text[] = "fox jumped over";

void setUp() {}
void tearDown() {}

void test_bob_up() {
    Swimmer swimmer = {200};
    bob_up(&swimmer);
    TEST_ASSERT_EQUAL(190, swimmer.y);
}

void test_sink() {
    Swimmer swimmer = {200};
    sink(&swimmer);
    TEST_ASSERT_EQUAL(201, swimmer.y);
}

void test_shift_pointer() {
    u8 i;
    Row row = {TEXT, 0};
    for (i = 0; i < 15; i++) {
        TEST_ASSERT_EQUAL(i, row.pos);
        shift_pointer(&row);
    }
}

void test_change_row() {
    int i;
    Row row = {TEXT, 0};

    for (i = 0; i < 15; i++) {
        TEST_ASSERT_EQUAL(TEXT[i], row.text[i]);
    }
    change_row(&row, new_text);
    for (i = 0; i < 15; i++) {
        TEST_ASSERT_EQUAL(new_text[i], row.text[i]);
    }
}

void test_increase_score() {
    Score score = {9998};
    increase_score(&score);
    TEST_ASSERT_EQUAL(9999, score.score);
    increase_score(&score);
    TEST_ASSERT_EQUAL(9999, score.score);
}

void test_tick_up() {
    Decorations decorations = {0};
    tick_up(&decorations);
    TEST_ASSERT_EQUAL(1, decorations.tick);
}

void test_start_game() {
    Model model = {{200}, {9998}, {TEXT, 0}, {10}};

    start_game(&model);
    TEST_ASSERT_EQUAL(150, model.swimmer.y);
    TEST_ASSERT_EQUAL(0, model.score.score);
    TEST_ASSERT_EQUAL(0, model.row.pos);
    TEST_ASSERT_EQUAL(0, model.decor.tick);
}

void test_key_press() {
    /* TODO FIX THIS*/

    /* Swimmer swimmer = {200}; */
    /* Score score = {0}; */
    /* Row row = {TEXT, 0}; */
    /**/
    /* Model model = { */
    /*     swimmer, */
    /*     score, */
    /*     row, */
    /* }; */
    /**/
    /* key_press('s', &model); */
    /* TEST_ASSERT_EQUAL(200, swimmer.y); */
    /* TEST_ASSERT_EQUAL(0, score.score); */
    /* TEST_ASSERT_EQUAL(0, row.pos); */
    /* key_press('t', &model); */
    /* TEST_ASSERT_EQUAL(190, swimmer.y); */
    /* TEST_ASSERT_EQUAL(1, score.score); */
    /* TEST_ASSERT_EQUAL(1, row.pos); */
}

void test_death() { death(); }

int main() {
    TEST_BEGIN();

    RUN_TEST(test_bob_up);
    RUN_TEST(test_sink);
    RUN_TEST(test_shift_pointer);
    RUN_TEST(test_change_row);
    RUN_TEST(test_increase_score);
    RUN_TEST(test_tick_up);
    RUN_TEST(test_start_game);
    RUN_TEST(test_key_press);
    RUN_TEST(test_death);

    TEST_END();
}
