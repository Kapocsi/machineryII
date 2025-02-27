/**
 * @file model.h
 * @brief Defines the game world objects.
 *
 * This file [FILL THIS IN].
 */

#ifndef MODEL_H
#define MODEL_H

#include "bitmap.h"

/**
 * @struct Swimmer
 * @brief Represents the player character.
 *
 * The Swimmer is constantly sinking, and will bob upwards if the player types
 * the correct input.
 */
 typedef struct {
    u16 x;        /* The x-coordinate of the left edge of the swimmer's sprite
                        on the screen*/
    u16 y;        /* The y-coordinate of the top edge of the swimmer's sprite
                        on the screen*/
    u8 sprite;    /* The index of the swimmer's current sprite based on the
                        sprite array*/
    BitMap sprites[2];   /* The array of all of the swimmer's sprites*/
} Swimmer;


/**
 * @struct Character
 * @brief Represents a stationary character slot.
 *
 * Displays a single character value.
 */
 typedef struct {
    u16 x;     /* The x-coordinate of the left edge of the character's sprite
                        on the screen*/
    u16 y;     /* The y-coordinate of the top edge of the character's sprite
                        on the screen*/
    u8 sprite; /* The index of the character's current sprite based on the
                        sprite array*/
    BitMap sprites[37];   /* The array of all of the character's sprites*/
} Character;


/**
 * @struct Pointer
 * @brief A horizontal line indicating the next letter to be typed.
 *
 * When the player presses the indicated letter, the pointer will shift to the
 * next letter.
 */
 typedef struct {
    u16 x_start;  /* The x-coordinate of the left side of the line at
                        position 0*/
    u16 x;        /* The x-coordinate of the left side of the line*/
    u16 y;        /* The y-coordinate of the line*/
    u8 length;    /* The length of the line in pixels*/
    u8 char_pos;  /* Which character the pointer is positioned under
                        in the row - left to right, 0 to (ROW_W - 1)*/
} Pointer;


/**
 * @struct Counter
 * @brief A string of numbers representing the player's point total.
 */
 typedef struct {
    u16 x;        /* The x-coordinate of the left edge of the leftmost
                        character sprite*/
    u16 y;        /* The y-coordinate of the top edge of the character
                        sprites*/
    u16 value;    /* The point value represented by the counter*/                    
    /*Character numbers[4];   /* The array of characters that form the counter*/
} Counter;


/* Decreases the swimmer's y value by a set amount */
void bob_up (Swimmer *swimmer);

/* Increases the swimmer's y value by a set amount */
void sink (Swimmer *swimmer);

/* Switches the swimmer's current sprite */
void switch_sprite (Swimmer *swimmer);

/* Sets the sprite of the character */
void set_char (Character *character, int char_index);

/* Increases the pointer's x value, or returns it to its starting position */
void shift_pointer (Pointer *pointer);

/* Increases the point value of the counter */
void increase_counter (Counter *counter);

 #endif