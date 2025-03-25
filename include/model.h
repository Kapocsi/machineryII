/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file model.h
 * @author Sylvie Mills
 * @brief Defines the game world objects and their functions.
 */

#ifndef MODEL_H
#define MODEL_H

#include "global.h"

/**
 * @struct Swimmer
 * @brief Represents the player character.
 *
 * The Swimmer is constantly sinking, and will bob upwards if the player types
 * the correct input.
 */
typedef struct {
    u16 y; /**The y-coordinate of the top edge of the swimmer's sprite
                 on the screen*/
} Swimmer;

/**
 * @struct Score
 * @brief A string of numbers representing the player's point total.
 */
typedef struct {
    u16 score; /**The player's point total*/
} Score;

/**
 * @struct Row
 * @brief A row of letters and spaces for the player to type.
 * The next character for the player to type is saved here, and is
 * identified by its position within the Row's string value.
 */
typedef struct {
    char text[128]; /**The string displayed in the row*/
    u8 pos;         /**The position of the next character to type in the row */
} Row;

/**
 * @struct Decorations
 * @brief The fish and kelp, which are unaffected by game input.
 */
typedef struct {
    u32 tick; /**The time that has passed since the game started*/
    /* T state */
} Decorations;

/**
 * @struct Model
 * @brief A single game state.
 */
typedef struct {
    Swimmer swimmer;
    Score score;
    Row row;
    Decorations decor;
} Model;

/**Decreases the swimmer's y value by a set amount */
void bob_up(Swimmer *swimmer);

/**Increases the swimmer's y value by a set amount */
void sink(Swimmer *swimmer);

/**Increases the pointer's x value, or returns it to its starting position */
void shift_pointer(Row *row);

/**Changes the text parameter of the letter row */
void change_row(Row *row, char *new_string);

/**Increases the point value of the counter */
void increase_score(Score *score);

/**Increases the tick counter by one */
void tick_up(Decorations *decorations);

/**Initialize model with default values */
void initModel(Model *m);

#endif
