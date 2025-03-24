#include "events.h"
#include "model.h"

void start_game(Model *model) {
    model->swimmer.y = 150;
    model->score.score = 0;
    model->row.pos = 0;
    model->decor.tick = 0;
}

void tick_increment(Model *model) {
    sink(&(model->swimmer));
}

void key_press(char key, Model *model) {
    if (key == (model->row.text)[model->row.pos]) {
        bob_up(&(model->swimmer));
        increase_score(&(model->score));
        shift_pointer(&(model->row));
    }
}

void death() { /* The "TODO()" macro messed with the model_t.c*/ }