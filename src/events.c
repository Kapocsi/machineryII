#include "events.h"
#include "model.h"
#include "psg.h"

void start_game(Model *model) { initModel(model); }

void tick_increment(Model *model) { sink(&(model->swimmer)); }

void key_press(char key) {
    Model *model = getModel();
    if (key == (model->row.text)[model->row.pos]) {
        bob_up(&(model->swimmer));
        increase_score(&(model->score));
        shift_pointer(&(model->row), &(model->buffer));
        bob_sound();
    }
}

void death() { death_sound(); }
