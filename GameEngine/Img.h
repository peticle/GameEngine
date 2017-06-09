#pragma once
#ifndef IMG_H
#define IMG_H

#include <SDL.h>
#include <string>
#include "Vector2.h"

// Manages the images
class Img {
public:

	/*** Constructors ***/

	Img();
	Img(std::string fileName, SDL_Renderer *render);

	/*** Destructors ***/

	~Img();

	/*** Getters ***/

	SDL_Texture *getTexture() const;
	SDL_Rect getRect() const;

	/*** Setters ***/

	void setTexture(SDL_Texture *textu);
	void setRect(SDL_Rect rect);

	/*** Public functions ***/

	// Draw the image on the window at a given position
	// param pos The position of the image
	// param render The renderer
	void draw(Vector2 pos, SDL_Renderer *render);

private:

	/*** Variables ***/

	SDL_Texture *textu;
	SDL_Rect rect;
};

#endif // IMG_H
