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
 * @brief The minimum permitted Swimmer y-coordinate.
 */
#define SW_MIN_Y = 100; 

/**
 * @brief The change in the swimmer's y-coordinate when they bob up.
 */
#define SW_SPEED = -10; 

/**
 * @brief The minimum permitted Pointer x-coordinate.
 */
#define PT_MIN_X = 60; 

/**
 * @brief The maximum permitted Pointer x-coordinate.
 */
#define PT_MAX_X = 580; 

/**
 * @struct Swimmer
 * @brief Represents the player character.
 *
 * The Swimmer is constantly sinking, and will bob upwards if the player types
 * the correct input.
 */
 typedef struct {
    const u16 x;    /* The x-coordinate of the left edge of the swimmer's sprite
                        on the screen*/
    u16 y;          /* The y-coordinate of the top edge of the swimmer's sprite
                        on the screen*/
    u8 sprite;      /* The index of the swimmer's current sprite based on the
                        sprite array*/
    BitMap sprites[2];   /* The array of all of the swimmer's sprites*/
} Swimmer;


/**
 * @struct Letter
 * @brief Represents a stationary letter slot.
 *
 * [FILL THIS IN].
 */
 typedef struct {
    const u16 x;    /* The x-coordinate of the left edge of the letter's sprite
                        on the screen*/
    const u16 y;    /* The y-coordinate of the top edge of the letter's sprite
                        on the screen*/
    u8 sprite;      /* The index of the letter's current sprite based on the
                        sprite array*/
    BitMap sprites[];   /* The array of all of the letter's sprites*/
} Letter;


/**
 * @struct Pointer
 * @brief A horizontal line indicating the next letter to be typed.
 *
 * [FILL THIS IN].
 */
 typedef struct {
    u16 x;          /* The x-coordinate of the left side of the line*/
    const u16 y;    /* The y-coordinate of the line*/
    const u8 length; /* The length of the line in pixels*/
} Pointer;



 #endif