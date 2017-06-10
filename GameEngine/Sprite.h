#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <vector>
#include "Img.h"

// Manage the sprites
class Sprite {
public:

	/*** Constructors ***/

	Sprite();
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once, bool pause);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once, bool pause, unsigned int startFrame, unsigned int endFrame);

	/*** Destructors ***/

	~Sprite();

	/*** Getters ***/

	Img *getImage() const;
	SDL_Rect getFirstFrameCrop() const;
	SDL_Rect getCurrentCrop() const;
	unsigned int getFrameNumber() const;
	unsigned int getStartFrame() const;
	unsigned int getCurrentFrame() const;
	unsigned int getEndFrame() const;
	bool getRotate() const;

	/*** Setters ***/

	void setImage(Img *image);
	void setFirstFrameCrop(SDL_Rect firstFrameCrop);
	void setFrameNumber(unsigned int frameNumber);
	void setStartFrame(unsigned int startFrame);
	void setCurrentFram(unsigned int currentFrame);
	void setEndFrame(unsigned int endFrame);
	void setRotate(bool rotate);

	/*** Public functions ***/

	// Update the frame of the sprite
	void update();
	void draw(Vector2 size, Vector2 pos, SDL_Renderer *render);

private:

	/*** Variables ***/

	Img *image;
	SDL_Rect firstFrameCrop;
	SDL_Rect currentCrop;
	unsigned int frameNumber;
	unsigned int startFrame;
	unsigned int currentFrame;
	unsigned int endFrame;
	unsigned int timePassed;
	bool rotate;
	bool pause;
	bool once;
};

#endif // SPRITE_H
