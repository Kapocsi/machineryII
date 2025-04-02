#include "words.h"
#include <stdlib.h>

/**
 * @brief The list of possible words to type.
 */
static const Word WORDS[] = {
    {6, "apple "},
    {5, "pear "},
    {7, "banana "}, 
    {6, "lemon "}, 
    {6, "fruit "},
    {7, "orange "},
    {6, "slice "},
    {6, "salad "},
    {5, "bowl "},
    {6, "yummy "}
};

/*Copy the Buffer's string into the game's Row struct*/
void transfer_string(RowBuffer *buffer, Row *row) {
    int char_i;
    for (char_i = 0; char_i < 25; char_i++) {
        row->text[char_i] = buffer->string[char_i];
    }
}

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

void next_row(RowBuffer *buffer, Row *row) {
    u8 char_i = 0;
    u8 index_i = 0;
    u16 current_word;
    u8 word_i;

    transfer_string(buffer, row);

    if (buffer->cutoff_i != 0) {
        char_i = insert_cutoff(buffer);
        index_i = 1;
    }

    /*Create a new row of random words*/
    while (char_i < 25) {
        current_word = rand() % 10;
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



