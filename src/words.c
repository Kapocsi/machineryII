#include "words.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * @brief The list of possible words to type.
 */
static const Word WORDS[] = {
    {6, "apple "},
    {5, "pear "},
    {7, "banana "}, 
    {6, "lemon "}
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

void next_row(RowBuffer *buffer, Row *row) {
    int j; /*Delete later*/
    u8 char_i;
    u8 index_i = 0;
    u16 current_word;
    u8 word_i;

    srand(time(NULL));

    /*Move the buffer data into the game's Row struct*/
    for (char_i = 0; char_i < 25; char_i++) {
        row->text[char_i] = buffer->string[char_i];
    }
    char_i = 0;

    printf("\n\nBuffer before: [");
    for (j = 0; j < 25; j++) {
        printf("%c", buffer->string[j]);
    }
    printf("]\n");

    if (buffer->cutoff_i != 0) {
        char_i = insert_cutoff(buffer);
        index_i = 1;
    }


    /*Create a new row of random words*/
    while (char_i < 25) {
        current_word = rand() % 4;

        printf("char_i = %d, ", char_i);    /*Delete later*/
        printf("current_word = %d, ", current_word);
        printf("word = ");
        for (j = 0; j < WORDS[current_word].length; j++) {
            printf("%c", WORDS[current_word].string[j]);
        }
        printf("\n");

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
    printf("Buffer after: [");
    for (j = 0; j < 25; j++) {
        printf("%c", buffer->string[j]);
    }
    printf("]\n");

}



