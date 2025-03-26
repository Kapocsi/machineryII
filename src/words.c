#include "words.h"

/**
 * @brief The list of possible words to type.
 */
static const Word WORDS[] = {
    {5, "apple"},
    {4, "pear"},
    {6, "banana"}
};

/*If a word was cut off at the end of the last row, put its remaining
      characters at the beginning of the new row*/
u8 insert_cutoff(RowBuffer *buffer) {
    u8 char_i;
    Word *cutoff_word = &(WORDS[buffer->indexes[24]]);
    u8 cutoff_length = WORDS[first_index].length - buffer->cutoff_i;

    for (char_i = 0; char_i < cutoff_length; char_i++) {
        buffer->string[char_i] = cutoff_word
            ->string[buffer->cutoff_i + char_i];
    }

    buffer->indexes[0] = buffer->indexes[24];

    return char_i;
}

void next_row(RowBuffer *buffer, Row *row) {
    u8 char_i;
    u8 index_i = 0;
    u8 first_index;
    u8 first_length;

    /*Move the buffer data into the game's Row struct*/
    for (char_i = 0; char_i < 25; char_i++) {
        row->text[char_i] = buffer->string[char_i];
    }
    char_i = 0;

    if (buffer->cutoff_i != 0) {
        char_i = insert_cutoff(buffer);
        index_i = 1;
    }

    
}

