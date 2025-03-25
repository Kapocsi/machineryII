/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file events.h
 * @author Sylvie Mills
 * @brief Defines the events that modify the game objects and game state.
 */

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/**Sets up the intial game state*/
void start_game(Model *model);

/** @brief Checks if the correct key is pressed, changes game state if so.
 * Increases the score, raises the swimmer, and shifts the row's character
 * pointer when the correct key is pressed */
void key_press(char key, Model *model);

/**Ends the game when the swimmer collides with the floor*/
void death();

#endif