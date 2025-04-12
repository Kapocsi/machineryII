/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file input.h
 * @author Thomas Kapocsi
 * @brief Defines the structures and functions for handling user input.
 */

#ifndef INPUT_H
#define INPUT_H

#include "global.h"

/**
 * @struct Mouse
 * @brief Represents the position of the mouse.
 */
typedef struct {
    int x;
    int y;
} Mouse;

/**
 * @struct inputState
 * @brief Represents the current state of input devices.
 */
typedef volatile struct {
    Mouse mouse;
    enum Bool capsLock;
    enum Bool shift;
} inputState;

/**
 * @brief Initializes the input system.
 *
 * @return A pointer to the initialized inputState structure.
 */
inputState *initInput();

/**
 * @brief Deinitializes the input system.
 *
 */
void deinitInput();

typedef enum { UNDEF = 0x80, CTRL, LSHIFT, RSHIFT, ALT, CAPS_LOCK } CTRL_CHARS;

#endif
