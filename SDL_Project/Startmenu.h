#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
class Startmenu
{
private:
	bool textures;
	SDL_Texture * Texture1;
	bool mouseup;
public:
	SDL_Event e;
	int Gamestate;
	SDL_Renderer* renderer;
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	void wind(SDL_Window* wind);		//create a renderer in wind
	Startmenu();
	void once();
	~Startmenu();
};

