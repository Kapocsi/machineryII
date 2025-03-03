#include "model.h"

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
static const u8 ROW_W = 15;

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

void change_row(Row *row, char *new_string) { row->text = new_string; }

void tick_up(Decorations *decorations) { (decorations->tick)++; }
