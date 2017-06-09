#include "Img.h"

#include <SDL_image.h>

/*** Constructors ***/
Img::Img() {}

Img::Img(std::string fileName, SDL_Rect rect, SDL_Renderer *render) {

	fileName = "img/" + fileName;
	SDL_Surface *loadSurf = IMG_Load(fileName.c_str());
	textu = SDL_CreateTextureFromSurface(render, loadSurf);
	SDL_FreeSurface(loadSurf);

	setRect(rect);
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

/*** Private functions ***/
void Img::prepareDraw(Vector2 size, Vector2 pos) {
	rect.w = size.getX();
	rect.h = size.getY();
	rect.x = pos.getX();
	rect.y = pos.getY();
}