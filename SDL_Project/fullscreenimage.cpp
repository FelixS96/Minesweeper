#include "fullscreenimage.h"


//create picture in renderer
fullscreenimage::fullscreenimage(std::string name, SDL_Renderer*renderer, int i)
{
	m = i;
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
	while (m==i) {
		SDL_PollEvent(&e);
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) {		//go back to startmenu
				m = 2;
				Mix_PlayChannel(-1, click, 0);
			}
		}
	}
	
}
//how to load textures
SDL_Texture* fullscreenimage::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

fullscreenimage::~fullscreenimage()
{
}
