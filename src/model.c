#include "model.h"
#include "global.h"
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

void initModel(Model *m) {
    memset(m, 0, sizeof(*m));
    m->score.score = DEFAULT_SCORE;
    m->swimmer.y = SWIMMER_START_POS;
    m->decor.tick = 0;
}

void bob_up(Swimmer *swimmer) {
    if (swimmer->y > SW_MIN_Y + SW_SPEED) {
        swimmer->y -= SW_SPEED;
    } else {
        swimmer->y = SW_MIN_Y;
    }
}

void sink(Swimmer *swimmer) { swimmer->y += 1; }

void shift_pointer(Row *row) {
    if (row->pos < ROW_W - 1) {
        (row->pos)++;
    } else {
        row->pos = 0;
    }
}

void increase_score(Score *score) {
    if (score->score < 9999)
        (score->score)++;
}

void change_row(Row *row, char *new_string) { strcpy(row->text, new_string); }

void tick_up(Decorations *decorations) { (decorations->tick)++; }
