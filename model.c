#include "model.h"

void bob_up (Swimmer *swimmer) {
    if (swimmer->y > SW_MIN_Y + SW_SPEED) {
        swimmer->y -= 10;
    } else {
        swimmer->y = SW_MIN_Y;
    }
}

void sink (Swimmer *swimmer) {
    swimmer->y += 1;
}

void switch_sprite (Swimmer *swimmer) {
    if (swimmer->sprite == 0) {
        swimmer->sprite = 1;
    } else {
        swimmer->sprite = 0;
    }
}

void