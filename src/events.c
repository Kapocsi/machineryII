#include "events.h"

void start_game(Swimmer *swimmer, Score *score, Row *row,
                Decorations *decorations) {
    swimmer->y = 150;
    score->score = 0;
    row->pos = 0;
    decorations->tick = 0;
}

void key_press(char key, Swimmer *swimmer, Score *score, Row *row) {
    if (key == (row->text)[row->pos]) {
        bob_up(swimmer);
        increase_score(score);
        shift_pointer(row);
    }
}

void death() { /* The "TODO()" macro messed with the model_t.c*/ }