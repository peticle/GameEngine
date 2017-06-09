#include "Sprite.h"

/*** Constructors ***/
Sprite::Sprite() {}

Sprite::Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
			   SDL_Renderer *render)
{
	setImage(image);
	setFirstFramePos(firstFramePos);
	setFrameSize(frameSize);
	setFrameNumber(frameNumber);
}

Sprite::Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
			   bool loop, bool pause, SDL_Renderer *render)
{
	setImage(image);
	setFirstFramePos(firstFramePos);
	setFrameSize(frameSize);
	setFrameNumber(frameNumber);
	setLoop(loop);
	setPause(pause);
}

Sprite::Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
			   bool loop, bool pause, bool rotate, SDL_Renderer *render)
{
	setImage(image);
	setFirstFramePos(firstFramePos);
	setFrameSize(frameSize);
	setFrameNumber(frameNumber);
	setLoop(loop);
	setPause(pause);
	setRotate(rotate);
}

Sprite::Sprite(Img *image, Vector2 firstFramePos, Vector2 frameSize, unsigned int frameNumber,
			   bool rotate, SDL_Renderer *render)
{
	setImage(image);
	setFirstFramePos(firstFramePos);
	setFrameSize(frameSize);
	setFrameNumber(frameNumber);
	setRotate(rotate);
}

/*** Destructors ***/
Sprite::~Sprite() {}

/*** Getters ***/
Img *Sprite::getImage() const {}

Vector2 Sprite::getFirstFramePos() const {}

Vector2 Sprite::getFrameSize() const {}

unsigned int Sprite::getFrameNumber() const {}

bool Sprite::getRotate() const {}

bool Sprite::getLoop() const {}

bool Sprite::getPause() const {}

/*** Setters ***/
void Sprite::setImage(Img *image) {}

void Sprite::setFirstFramePos(Vector2 pos) {}

void Sprite::setFrameSize(Vector2 size) {}

void Sprite::setFrameNumber(unsigned int frameNumber) {}

void Sprite::setRotate(bool rotate) {}

void Sprite::setLoop(bool loop) {}

void Sprite::setPause(bool pause) {}

/*** Public functions ***/
void Sprite::update() {}