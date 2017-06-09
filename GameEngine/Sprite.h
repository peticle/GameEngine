#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "Img.h"

// Manage the sprites
class Sprite {
public:

	/*** Constructors ***/

	Sprite();
	Sprite(std::vector<Img *> anim, std::vector<unsigned int> delay, bool rotate, SDL_Renderer *render);

	/*** Destructors ***/

	~Sprite();

	/*** Public functions ***/

	// Update the frame of the sprite
	void update();

private:

	/*** Variables ***/

	std::vector<Img *> anim;
	std::vector<unsigned int> delay;
	unsigned int currentFrame;
	unsigned int startFrame;
	unsigned int endFrame;
	unsigned long timePassed;
};

#endif // SPRITE_H
