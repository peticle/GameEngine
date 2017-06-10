#include "Sprite.h"
#include <iostream>

/*** Constructors ***/
Sprite::Sprite() {}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	startFrame = 0;
	endFrame = frameNumber - 1;
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
	endFrame = frameNumber - 1;
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
	endFrame = frameNumber - 1;
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
	endFrame = frameNumber - 1;
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

	// Animate the sprite if not paused
	if(!pause) {

		unsigned int ticks = SDL_GetTicks();

		if (ticks > timePassed + 100) {

			// Check if the image and the texture of the image exists
			if (image != NULL && image->getTexture() != NULL) {

				// Ajust the index of the frame
				if(currentFrame < endFrame)
					currentFrame++;
				else {
					if(!once) {
						currentFrame = startFrame;
						currentCrop = firstFrameCrop;
					} else {
						pause = true;
					}
				}

				/// Ajouter propriété dans la classe img
				int textuW = 0;
				SDL_QueryTexture(image->getTexture(), NULL, NULL, &textuW, NULL);

				// Get number of image per line possible
				int numPerLine = textuW / firstFrameCrop.w;

				// Get the number of time the image excess the first line (with a merge of 1 px)
				int excess = firstFrameCrop.w / ((textuW - currentCrop.x) + 1);

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
	image->draw(size, pos, currentCrop, rotate, render);
}