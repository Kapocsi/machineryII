# Game Proposal.

Title Ideas
- Stay Afloat (current)
- Below C
- Man Over Board (like keyboard. get it? cause you're also a man over a board)

QUESTIONS FOR THOMAS:
- Should the pointer (the box that surrounds the next key to be typed) progress when any key is pressed, or only when the correct key has been pressed? I think the former would make for smoother gameplay, but it would mean we would have to change the colours of the correctly-typed letters if we wanted the player to know whether or not they'd made a mistake. The second option would be easier to implement.
- If we decide to implement an air mechanic, we should probably have a meter on screen (something basic, like a loading-screen meter). It would decrease at a consistent pace while the swimmer is underwater. How should it increase when the swimmer is above water? Consistently, twice as fast, maybe?

## General Game Overview

- The intial splash screen shows the game title. The buttons labeled as "1 Player" and "2 Player" appear once the game setup is complete.
- In both game modes, the player must correctly type a string of words at the bottom of their screen in order to keep the swimmer (the player character) from drowning.
- The game display will consist of (from top-to-bottom): the score (a number in the upper corner), the surface of the water (a squggled line across the screen), the swimmer, the sea floor (a straight line across the screen, with sea grass sticking out of the top), and the row of words.
- The swimmer sinks at a consistent rate. Every time a correct letter is typed, the swimmer bobs upward a set amount.
- The next letter to type will be indicated by the pointer (a line below the letter). When the correct letter is typed, the pointer will progress to the right. When all the letters in the row have been typed, the pointer will move to the far left of the screen, and a new row of words will appear.
- When a correct letter is typed, the score will increase.
- The game will end when the swimmer touches the sea floor.
- During a game-over, the gameplay will freeze and a display window somewhat smaller than the screen will appear. Version-specific text will be displayed in the window, and the player's score will be displayed below that.
- If there is time during development, additional features will be added:
  1. Instead of sinking at a consistent speed, the swimmer's vertical movements will have inertia (sinking will increase in speed as more time passes without a push upwards).
  2. Instead of the game ending when the swimmer touches the sea floor, there will be an air mechanic. A meter in the upper corner across from the score will show how much air the swimmer has left. It will decrease steadily while the swimmer's head is below water, and increase twice as fast when the swimmer's head is above water.
  3. The difficulty of the game will increase at a steady pace. This either means that the swimmer will sink faster, or that the air will decrease faster. 
  4. Additional animations will be added to pre-existing elements: the water surface's waves will move instead of it appearing as a static line, the sea grass on the sea floor will move, the swimmer will have a particular animation for when they swim up, and the swimmer's neutral animation will become more frantic as the difficulty increases.
  5. Fish will be added as decoration, and will move across the screen left-to-right in the water.
  6. The game over will feature an animation depicting the swimmer's demise before the display window appears.

## Game Play Details for Core 1-Player Version

## Game Play Details for Core 2-Player Version

## Sound Effects

- A splash sound plays every time the swimmer bobs its head above the water.
- An ascending "bwoop" noise plays when a correct key is pressed and the swimmer bobs upward.
- A few descending notes play when the player loses.
- A few ascending notes play if the player wins (2 player version only).
- Background music: An original composition with basic synthesized notes. The speed of the song will increase as the game difficulty increases.

## Additional Features
