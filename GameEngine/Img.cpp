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
SDL_Texture *Img::getTexture() const {}

SDL_Rect Img::getRect() const {}

/*** Setters ***/
void Img::setTexture(SDL_Texture *textu) {}

void Img::setRect(SDL_Rect rect) {}

/*** Public functions ***/
void Img::draw(Vector2 pos, SDL_Renderer *render) {}