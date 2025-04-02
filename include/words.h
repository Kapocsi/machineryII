/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file words.h
 * @author Sylvie Mills
 * @brief Defines the functions involving the row of words to type.
 */

#ifndef WORDS_H
#define WORDS_H
 
#include "global.h"
#include "model.h"

/**
 * @struct Word
 * @brief An array of characters, the array length at the head.
 */
 typedef struct {
    u8 length;      /**The number of letters in the word*/
    char *string;   /**The word's string value*/
} Word;

/**
 * @struct RowBuffer
 * @brief A place to store the next row of words.
 */
 typedef struct {
    u8 cutoff_i;    /** The index (in the cutoff word) of the first
                     * cutoff character */
    u8 last_i;      /** The index of the first slot of free memory
                     * in the 'indexes' array*/
    u8 indexes[6];  /** An ordered list of the words stored in the
                     * buffer string*/
    char *string;   /** The contents of the buffer */
} RowBuffer;

/**Transfer the buffer's string to the row, then create a new string
 * for the buffer to store.
 * NOTE: The function 'srand(time(NULL));' must be invoked once by the calling
 * module before any calls of this method. */
void next_row(RowBuffer *buffer, Row *row);

#endif