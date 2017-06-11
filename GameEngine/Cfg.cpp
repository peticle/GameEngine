#include "Cfg.h"

/*** Constructors ***/
Cfg::Cfg() {
	gameWidth = 640;
	gameHeight = 480;
}

/*** Getters ***/
int Cfg::getGameWidth() {
	return gameWidth;
}

int Cfg::getGameHeight() {
	return gameHeight;
}

std::map<std::string, SDL_Scancode> Cfg::getControls() {
	return controls;
}

std::map<std::string, SDL_Scancode> Cfg::getAltControls() {
	return altControls;
}

/*** Setters ***/
void Cfg::setGameWidth(int gameWidth) {
	Cfg::gameWidth = gameWidth;
}

void Cfg::setGameHeight(int gameHeight) {
	Cfg::gameHeight = gameHeight;
}

void Cfg::setControls(std::map<std::string, SDL_Scancode> controls) {
	Cfg::controls = controls;
}

void Cfg::setAltControls(std::map<std::string, SDL_Scancode> altControls) {
	Cfg::altControls = altControls;
}