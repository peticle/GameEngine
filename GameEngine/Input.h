#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

// A class who handle the inputs
class Input {
public:

	/*** Constructors ***/

	Input();

	/*** Public functions ***/

	// Clear the states of the keys
	void clearKeysState();

	// Add the keys who are pressed to the correspondent array
	// param event The event listener
	void keyDownEvent(SDL_Event& event);

	// Add the keys who are released to the correspondent array
	// param event The event listener
	void keyUpEvent(SDL_Event& event);

	// Check if a given key was pressed during the current frame
	// param key The key to check
	// return If the key is pressed or not
	bool wasKeyPressed(SDL_Scancode key);

	// Check if a given key was released during the current frame
	// param key The key to check
	// return If the key is released or not
	bool wasKeyReleased(SDL_Scancode key);

	// Check if a given key is currently being held
	// param key The key to check
	// return If the key is being held or not
	bool isKeyHeld(SDL_Scancode key);

private:

	/*** Variables ***/
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> pressedKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
};

#endif // INPUT_H