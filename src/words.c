#include "words.h"

/**
 * @brief The list of possible words to type.
 */
static const Word WORDS[] = {
    {5, "apple"},
    {4, "pear"},
    {6, "banana"}
};

void next_row(RowBuffer *buffer, Row *row) {
    int char_i;
    int index_i = 0;
    int first_index;
    int first_length;

    for (char_i = 0; char_i < 25; char_i++) {
        row->text[char_i] = buffer->row_buffer[char_i];
    }
    char_i = 0;

    if (buffer->cutoff != 0) {
        first_index = buffer->indexes[24];

        for (; char_i < buffer->cutoff; char_i++) {
            buffer->row_buffer[char_i] = WORDS[first_index]
                .string[buffer->cutoff + char_i];
        }
        buffer->indexes[0] = first_index;
        index_i = 1;
    }

    
}