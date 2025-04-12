#include "model.h"
#include "global.h"
#include "words.h"
#include <string.h>

/**
 * @brief The minimum permitted Swimmer y-coordinate.
 */
static const u32 SW_MIN_Y = 100;

/**
 * @brief The subtraction from the swimmer's y-coordinate
 * when they bob up.
 */
static const u8 SW_SPEED = 10;

/**
 * @brief The number of characters in the typing row
 */
static const u8 ROW_W = 25;

#define DEFAULT_SCORE 0
#define SWIMMER_START_POS 64

static Model *model;

void initModel(Model *m) {
    memset(m, 0, sizeof(*m));
    m->score.score = DEFAULT_SCORE;
    m->swimmer.y = SWIMMER_START_POS;
    m->decor.tick = 0;
    new_row(&(m->buffer));
    change_row(&(m->row), m->buffer.string);
    new_row(&(m->buffer));

    model = m;
}

void bob_up(Swimmer *swimmer) {
    if (swimmer->y > SW_MIN_Y + SW_SPEED) {
        swimmer->y -= SW_SPEED;
    } else {
        swimmer->y = SW_MIN_Y;
    }
}

void sink(Swimmer *swimmer) {
    /** Stop lowerin the swimmer once it hit's the the text */
    if (swimmer->y++ > 200)
        swimmer->y--;
}

void shift_pointer(Row *row, RowBuffer *buffer) {
    if (row->pos < ROW_W - 1) {
        (row->pos)++;
    } else {
        change_row(row, (buffer->string));
        new_row(buffer);
        row->pos = 0;
    }
}

void increase_score(Score *score) {
    if (score->score < 9999)
        (score->score)++;
}

void change_row(Row *row, char new_string[25]) {
    strcpy(row->text, new_string);
}

void tick_up(Decorations *decorations) { (decorations->tick)++; }

Model *getModel() { return model; }
