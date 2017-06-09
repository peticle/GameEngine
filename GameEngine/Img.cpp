#include "Img.h"

/*** Constructors ***/
Img::Img() {}

Img::Img(std::string fileName, SDL_Renderer *render) {}

/*** Destructors ***/
Img::~Img() {}

/*** Getters ***/
SDL_Texture *Img::getTexture() const {}

SDL_Rect Img::getRect() const {}

/*** Setters ***/
void Img::setTexture(SDL_Texture *textu) {}

void Img::setRect(SDL_Rect rect) {}

/*** Public functions ***/
void Img::draw(Vector2 pos, SDL_Renderer *render) {}