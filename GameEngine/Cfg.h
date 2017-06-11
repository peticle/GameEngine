#pragma once
#ifndef CFG_H
#define CFG_H

#include <SDL.h>
#include <string>
#include <map>

class Cfg {
public:

	/*** Constructors ***/

	Cfg();

	/*** Getters ***/

	static int getGameWidth();
	static int getGameHeight();
	static std::map<std::string, SDL_Scancode> getControls();
	static std::map<std::string, SDL_Scancode> getAltControls();

	/*** Setters ***/

	static void setGameWidth(int gameWidth);
	static void setGameHeight(int gameHeight);
	static void setControls(std::map<std::string, SDL_Scancode> controls);
	static void setAltControls(std::map<std::string, SDL_Scancode> altControls);

private:

	/*** Variables ***/

	static int gameWidth;
	static int gameHeight;
	static std::map<std::string, SDL_Scancode> controls;
	static std::map<std::string, SDL_Scancode> altControls;
};

#endif // CFG_H
