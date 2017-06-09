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
	Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize,unsigned int frameNumber,
		   SDL_Renderer *render);
	Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
		   bool loop, bool pause, SDL_Renderer *render);
	Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
		   bool loop, bool pause, bool rotate, SDL_Renderer *render);
	Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
		   bool rotate, SDL_Renderer *render);

	/*** Destructors ***/

	~Sprite();

	/*** Getters ***/

	Img *getImage() const;
	Vector2 getFirstFramePos() const;
	Vector2 getFrameSize() const;
	unsigned int getFrameNumber() const;
	bool getRotate() const;
	bool getLoop() const;
	bool getPause() const;

	/*** Setters ***/

	void setImage(Img *image);
	void setFirstFramePos(Vector2 pos);
	void setFrameSize(Vector2 size);
	void setFrameNumber(unsigned int frameNumber);
	void setRotate(bool rotate);
	void setLoop(bool loop);
	void setPause(bool pause);

	/*** Public functions ***/

	// Update the frame of the sprite
	void update();

private:

	/*** Variables ***/

	Img *image;
	Vector2 firstFramePos;
	Vector2 frameSize;
	unsigned int frameNumber;
	bool rotate;
	bool loop;
	bool pause;
	unsigned long timePassed;
};

#endif // SPRITE_H
