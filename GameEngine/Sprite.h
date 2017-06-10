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
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, float delay);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, float delay);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once, float delay);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once, bool pause, float delay);
	Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int startFrame, unsigned int endFrame, unsigned int frameNumber, bool rotate, bool once, bool pause, float delay);

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
	unsigned int getTimePassed() const;
	bool getRotate() const;
	bool getPause() const;
	bool getOnce() const;
	float getDelay() const;

	/*** Setters ***/

	void setImage(Img *image);
	void setFirstFrameCrop(SDL_Rect firstFrameCrop);
	void setCurrentCrop(SDL_Rect currentCrop);
	void setFrameNumber(unsigned int frameNumber);
	void setStartFrame(unsigned int startFrame);
	void setCurrentFrame(unsigned int currentFrame);
	void setEndFrame(unsigned int endFrame);
	void setTimePassed(unsigned int timePassed);
	void setRotate(bool rotate);
	void setPause(bool pause);
	void setOnce(bool once);
	void setDelay(float delay);

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
	float delay;
};

#endif // SPRITE_H
