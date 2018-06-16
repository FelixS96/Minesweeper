#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
class Startmenu
{
private:
	bool textures;
	SDL_Texture * Texture1;
	SDL_Texture * Texture2;
public:
	bool mouseup;
	SDL_Event e;
	int Gamestate;
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	Startmenu();
	void once(SDL_Renderer* renderer);
	void update(SDL_Renderer* renderer);
	int selected;
	~Startmenu();
};

