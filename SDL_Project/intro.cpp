#include "intro.h"



intro::intro(std::string name, SDL_Renderer*renderer)
{
	m =0;
	Texture1 = loadTexture(name, renderer);
	SDL_Rect rect;
	rect.h = 950;
	rect.w = 1600;
	rect.x = 0;
	rect.y = 0;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Texture1, NULL, &rect);

	//show renderer
	SDL_RenderPresent(renderer);
	while (m == 0) {
		SDL_PollEvent(&e);
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_RETURN) {		//go back to startmenu
				printf("enter");
				m = 2;
			}
		}
	}
}
//how to load textures
SDL_Texture* intro::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

intro::~intro()
{
}
