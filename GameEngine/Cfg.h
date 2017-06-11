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

private:

	/*** Variables ***/
	static int gameWidth;
	static int gameHeight;
	static std::map<std::string, std::pair<SDL_Scancode, SDL_Scancode>> controls;
};

#endif // CFG_H
