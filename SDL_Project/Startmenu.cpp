#include "Startmenu.h"



SDL_Texture * Startmenu::loadTexture(std::string path, SDL_Renderer * renderer)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

void Startmenu::wind(SDL_Window * wind)
{
	renderer = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);
}

Startmenu::Startmenu()
{
	this->Gamestate = 1;
	textures = false;
}

void Startmenu::once()
{
	while (Gamestate == 1) {
		if (textures == false) {
			Texture1 = loadTexture("title.png", renderer);
			textures = true;
		}
		//target rect for rendering tasks
		SDL_Rect rect;
		//set rect size
		rect.w = 1600;
		rect.h = 950;
		rect.x = 0;
		rect.y = 0;
		//clear renderer
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Texture1, NULL, &rect);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {				//exit button
			Gamestate = 0;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT && mouseup == false) {
				Gamestate = 2;
			}
		}
	}
}


Startmenu::~Startmenu()
{
}
