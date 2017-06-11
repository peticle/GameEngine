#include "Cfg.h"

// Declaration of the statics
int Cfg::gameWidth = 1920;
int Cfg::gameHeight = 1080;
std::map<std::string, SDL_Scancode> Cfg::controls;
std::map<std::string, SDL_Scancode> Cfg::altControls;

/*** Constructors ***/
Cfg::Cfg() {}

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