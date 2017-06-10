#include "Img.h"

#include <SDL_image.h>

/*** Constructors ***/
Img::Img() {}

Img::Img(std::string fileName, SDL_Renderer *render) {

	fileName = "img/" + fileName;
	SDL_Surface *loadSurf = IMG_Load(fileName.c_str());
	textu = SDL_CreateTextureFromSurface(render, loadSurf);

	// Set the variable textuSize
	int textuW = 0;
	int textuH = 0;
	SDL_QueryTexture(textu, NULL, NULL, &textuW, &textuH);
	textuSize = Vector2(textuW, textuH);

	SDL_FreeSurface(loadSurf);
}

/*** Destructors ***/
Img::~Img() {
	SDL_DestroyTexture(textu);
}

/*** Getters ***/
SDL_Texture *Img::getTexture() const {
	return textu;
}

SDL_Rect Img::getRect() const {
	return rect;
}

Vector2 Img::getTextuSize() const {
	return textuSize;
}

/*** Setters ***/
void Img::setTexture(SDL_Texture *textu) {
	this->textu = textu;
}

void Img::setRect(SDL_Rect rect) {
	this->rect = rect;
}

/*** Public functions ***/
void Img::draw(Vector2 size, Vector2 pos, SDL_Renderer *render) {

	prepareDraw(size, pos);
	SDL_RenderCopy(render, textu, NULL, &rect);
}

void Img::draw(Vector2 size, Vector2 pos, bool rotate, SDL_Renderer *render) {

	prepareDraw(size, pos);

	if (!rotate)
		SDL_RenderCopy(render, textu, NULL, &rect);
	else
		SDL_RenderCopyEx(render, textu, NULL, &rect, 180.0, NULL, SDL_FLIP_VERTICAL);
}

void Img::draw(Vector2 size, Vector2 pos, SDL_Rect crop, SDL_Renderer *render) {

	prepareDraw(size, pos);
	SDL_RenderCopy(render, textu, &crop, &rect);
}

void Img::draw(Vector2 size, Vector2 pos, SDL_Rect crop, bool rotate, SDL_Renderer *render) {
	
	prepareDraw(size, pos);

	if (!rotate)
		draw(size, pos, crop, render);
	else
		SDL_RenderCopyEx(render, textu, &crop, &rect, 180.0, NULL, SDL_FLIP_VERTICAL);
}

/*** Private functions ***/
void Img::prepareDraw(Vector2 size, Vector2 pos) {
	rect.w = size.getX();
	rect.h = size.getY();
	rect.x = pos.getX();
	rect.y = pos.getY();
}