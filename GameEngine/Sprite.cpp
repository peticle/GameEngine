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
}

/*** Destructors ***/
Sprite::~Sprite() {
	delete image;
	image = NULL;
}

/*** Public functions ***/
void Sprite::update() {

	timePassed += SDL_GetTicks() / 1000.0;

	if(timePassed >= 1) {

		std::cout << "1sec\n";

		currentFrame = (currentFrame != endFrame) ? currentFrame + 1 : 0;

		currentCrop = firstFrameCrop;
		currentCrop.x = currentCrop.w * currentFrame;

		int textuW = 0;
		SDL_QueryTexture(image->getTexture(), NULL, NULL, &textuW, NULL);

		if (textuW / currentCrop.w * (currentFrame + 1) > 0)
			currentCrop.y = currentCrop.h * (currentCrop.w * (currentFrame + 1));

		timePassed = 0;
	}
}

void Sprite::draw(Vector2 size, Vector2 pos, SDL_Renderer *render) {

}