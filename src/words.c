#include "words.h"
#include <stdlib.h>

/**
 * @brief The list of possible words to type.
 */
static const Word WORDS[] = {
    {4, "air "},
    {4, "bob "},
    {4, "eel "},
    {4, "man "},
    {4, "sea "},
    {4, "sky "},
    {4, "try "},
    {5, "boat "},
    {5, "buoy "},
    {5, "dive "},
    {5, "down "},
    {5, "fish "},
    {5, "help "},
    {5, "kelp "},
    {5, "land "},
    {5, "over "},
    {5, "rise "},
    {5, "sink "},
    {5, "sunk "},
    {5, "swim "},
    {6, "board "},
    {6, "death "},
    {6, "drown "},
    {6, "fight "},
    {6, "ocean "},
    {6, "shark "},
    {6, "shore "},
    {6, "tidal "},
    {6, "under "},
    {6, "water "}
};

/*If a word was cut off at the end of the last row, put its remaining
      characters at the beginning of the new row*/
u8 insert_cutoff(RowBuffer *buffer) {
    u8 char_i;
    Word *cutoff_word = &(WORDS[buffer->indexes[buffer->last_i - 1]]);
    u8 cutoff_length = cutoff_word->length - buffer->cutoff_i;

    for (char_i = 0; char_i < cutoff_length; char_i++) {
        buffer->string[char_i] = cutoff_word
            ->string[buffer->cutoff_i + char_i];
    }

    buffer->indexes[0] = buffer->indexes[buffer->last_i - 1];
    buffer->last_i = 1;

    return char_i;
}

void new_row(RowBuffer *buffer) {
    u8 char_i = 0;
    u8 index_i = 0;
    u16 current_word;
    u8 word_i;

    if (buffer->cutoff_i != 0) {
        char_i = insert_cutoff(buffer);
        index_i = 1;
    }

    /*Create a new row of random words*/
    while (char_i < 25) {
        current_word = rand() % 30;
        buffer->cutoff_i = 0;
        word_i = 0;
        buffer->indexes[buffer->last_i] = current_word;
        buffer->last_i++;

        while (char_i < 25 && word_i < WORDS[current_word].length) {
            buffer->string[char_i] = WORDS[current_word].string[word_i];
            char_i++;
            word_i++;
            (buffer->cutoff_i)++;
        }
    }
}



