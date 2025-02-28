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

void switch_sprite(Swimmer *swimmer) {
    if (swimmer->sprite == 0) {
        swimmer->sprite = 1;
    } else {
        swimmer->sprite = 0;
    }
}

void set_char(Character *character, int char_index) {
    character->sprite = char_index;
}

void shift_pointer(Pointer *pointer) {
    if (pointer->char_pos < ROW_W - 1) {
        (pointer->char_pos)++;
        pointer->x += pointer->length;
    } else {
        pointer->char_pos = 0;
        pointer->x = pointer->x_start;
    }
}

void increase_counter(Counter *counter) { (counter->value)++; }


void change_row(Row *row, char *new_string) {
    u8 i;
    Character *letters = row->letters;
    for (i = 0; i < 15; i++) {
        letters[i].sprite = new_string[i] - 0 ;
    }
    row->value = new_string;
    
}
