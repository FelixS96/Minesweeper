#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
class fullscreenimage
{
public:
	fullscreenimage(std::string name, SDL_Renderer* renderer, int i);
	SDL_Texture* Texture1;
	int m;
	SDL_Event e;
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	~fullscreenimage();
};

