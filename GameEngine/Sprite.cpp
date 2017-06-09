#include "Sprite.h"

/*** Constructors ***/
Sprite::Sprite() {}

Sprite::Sprite(Img *image, SDL_Rect firstFrameCrop, unsigned int frameNumber) {
	this->image = image;
	this->firstFrameCrop = firstFrameCrop;
	this->frameNumber = frameNumber;
}

/*** Destructors ***/
Sprite::~Sprite() {
	delete image;
	image = NULL;
}

/*** Public functions ***/
void Sprite::update() {}