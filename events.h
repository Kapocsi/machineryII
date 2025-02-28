/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file events.h
 * @author Sylvie Mills
 * @brief Defines the events that modify the game objects and game state.
 */

 #ifndef EVENTS_H
 #define EVENTS_H

#include "model.h"

/*Within,
develop “event handler” functions which update the model’s state for each kind of synchronous,
asynchronous and condition-based game event. The actual events won’t be occurring yet, but
their handlers can still be implemented and tested. These functions will delegate some or all
of their tasks to model functions.*/

/*
Events:
Correct key input
Death
Mouse press
Mouse press in start box
New row is written
Animate/Update Game
*/

/**Updates the display to represent the current game state*/
void update();

/**Increases the swimmer's y coordinate*/
void swimmer_sinks(Swimmer *swimmer);

/**Begins the game when the mouse clicks the start button*/
void start_game();

/**Increases the counter and raises the swimmer when the correct key is pressed */
void correct_key(Swimmer *swimmer, Counter *counter);



/**Ends the game when the swimmer collides with the floor*/
void death();



#endif