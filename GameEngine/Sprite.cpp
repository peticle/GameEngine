#include "Sprite.h"
#include <iostream>

/*** Constructors ***/
Sprite::Sprite() {}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
	startFrame = 0;
	currentFrame = 0;
	endFrame = frameNumber - 1;
	rotate = false;
	timePassed = 0;
}

/*** Destructors ***/
Sprite::~Sprite() {
	delete image;
	image = NULL;
}

/*** Public functions ***/
void Sprite::update() {

	unsigned int ticks = SDL_GetTicks();

	if(ticks > timePassed + 1000) {

		currentFrame = (currentFrame != endFrame) ? currentFrame + 1 : 0;

		currentCrop = firstFrameCrop;
		currentCrop.x = currentCrop.w * currentFrame;

		if(image != NULL && image->getTexture() != NULL) {
			int textuW = 0;
			int textuH = 0;
			SDL_QueryTexture(image->getTexture(), NULL, NULL, &textuW, &textuH);

			if (textuW / currentCrop.w * (currentFrame + 1) > 0)
				currentCrop.y = currentCrop.h * (currentCrop.w * (currentFrame + 1));
		}

		timePassed = ticks;
	}
}

void Sprite::draw(Vector2 size, Vector2 pos, SDL_Renderer *render) {

}