/* Unit tests for model.c and events.c  */

#include "unit.h"

#include "events.h"
#include <stdio.h>

#define TEXT "the quick brown fox jumpe"
static const char new_text[] = "d over the lazy dog the q";

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

void test_shift_pointer() {}

void test_change_row() {
    int i;
    Row row = {TEXT, 0};

    for (i = 0; i < 25; i++) {
        TEST_ASSERT_EQUAL(TEXT[i], row.text[i]);
    }
    change_row(&row, new_text);
    for (i = 0; i < 25; i++) {
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

/*memset(m, 0, sizeof(*m));
    m->score.score = DEFAULT_SCORE;
    m->swimmer.y = SWIMMER_START_POS;
    m->decor.tick = 0;
    new_row(&(m->buffer));
    change_row(&(m->row), m->buffer.string);
    new_row(&(m->buffer));*/

void test_start_game() {
    Model model;

    start_game(&model);
    TEST_ASSERT_EQUAL(64, model.swimmer.y);
    TEST_ASSERT_EQUAL(0, model.score.score);
    TEST_ASSERT_EQUAL(0, model.row.pos);
    TEST_ASSERT_EQUAL(0, model.decor.tick);
}

void test_key_press() {
    Model model = {
        {200}, 
        {0}, 
        {TEXT, 0}, 
        {0, 0, {0, 0, 0, 0, 0, 0}, ""}, 
        {0}
    }; 
    
    key_press('s'); 
    TEST_ASSERT_EQUAL(200, model.swimmer.y); 
    TEST_ASSERT_EQUAL(0, model.score.score); 
    TEST_ASSERT_EQUAL(0, model.row.pos); 
    key_press('t'); 
    TEST_ASSERT_EQUAL(190, model.swimmer.y); 
    TEST_ASSERT_EQUAL(1, model.score.score); 
    TEST_ASSERT_EQUAL(1, model.row.pos);
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
