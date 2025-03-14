#include "events.h"

void start_game(Model *model) {
    model->swimmer.y = 150;
    model->score.score = 0;
    model->row.pos = 0;
    model->decor.tick = 0;
}

void key_press(char key, Swimmer *swimmer, Score *score, Row *row) {
    if (key == (row->text)[row->pos]) {
        bob_up(swimmer);
        increase_score(score);
        shift_pointer(row);
    }
}

void death() { /* The "TODO()" macro messed with the model_t.c*/ }