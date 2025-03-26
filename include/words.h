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
    u8 cutoff_i;        /**The index of the first cutoff character */
    u8 indexes[25];
    char *string;
} RowBuffer;

/**Set t*/
void next_row(RowBuffer *buffer, Row *row);

#endif