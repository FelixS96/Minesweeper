#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	Game* Game1 = new Game();

	SDL_Quit();
	return 0;
}