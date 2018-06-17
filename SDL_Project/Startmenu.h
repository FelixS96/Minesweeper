#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include "fullscreenimage.h"
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
	Mix_Chunk *one = NULL;
	fullscreenimage * fullscreen;
	Startmenu();
	void once(SDL_Renderer* renderer);
	void update(SDL_Renderer* renderer);
	int selected;
	~Startmenu();
};

