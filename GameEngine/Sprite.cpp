#include "Sprite.h"
#include <iostream>

/*** Constructors ***/
Sprite::Sprite() {}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	startFrame = 0;
	endFrame = frameNumber;
	rotate = false;
	once = false;
	pause = false;
	currentCrop = firstFrameCrop;
	currentFrame = startFrame;
	timePassed = 0;
}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	this->rotate = rotate;
	startFrame = 0;
	endFrame = frameNumber;
	once = false;
	pause = false;
	currentCrop = firstFrameCrop;
	currentFrame = startFrame;
	timePassed = 0;
}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	this->rotate = rotate;
	this->once = once;
	startFrame = 0;
	endFrame = frameNumber;
	pause = false;
	currentCrop = firstFrameCrop;
	currentFrame = startFrame;
	timePassed = 0;
}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber, bool rotate, bool once, bool pause) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	this->rotate = rotate;
	this->once = once;
	this->pause = pause;
	startFrame = 0;
	endFrame = frameNumber;
	currentCrop = firstFrameCrop;
	currentFrame = startFrame;
	timePassed = 0;
}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int startFrame, unsigned int endFrame, unsigned int frameNumber, bool rotate, bool once, bool pause) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->frameNumber = frameNumber;
	this->rotate = rotate;
	this->once = once;
	this->pause = pause;
	currentCrop = firstFrameCrop;
	currentFrame = startFrame;
	timePassed = 0;
}

/*** Destructors ***/
Sprite::~Sprite() {
	delete image;
	image = NULL;
}

SDL_Rect Sprite::getCurrentCrop() const {
	return currentCrop;
}

Img *Sprite::getImage() const {
	return image;
}

/*** Public functions ***/
void Sprite::update() {

	// Check if animation is not paused
	if(!pause) {

		unsigned int ticks = SDL_GetTicks();

		if (ticks > timePassed + 100) {

			if (image != NULL && image->getTexture() != NULL) {

				// Ajust the index of the frame
				if (currentFrame < endFrame - 1)
					currentFrame++;
				else {
					currentFrame = startFrame;
					currentCrop = firstFrameCrop;
				}

				int textuW = 0;
				SDL_QueryTexture(image->getTexture(), NULL, NULL, &textuW, NULL);

				int numPerLine = textuW / firstFrameCrop.w;
				int excess = firstFrameCrop.w / (textuW - currentCrop.x);

				// Ajuste la position de l'image
				currentCrop.x = currentCrop.w * (currentFrame % numPerLine);
				currentCrop.y = currentCrop.h * excess + currentCrop.y;
			}

			timePassed = ticks;
		}
	}
}

void Sprite::draw(Vector2 size, Vector2 pos, SDL_Renderer *render) {
	update();
	image->draw(size, pos, currentCrop, render);
}