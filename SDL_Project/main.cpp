#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Test", 50, 50, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	double i = 0;
	SDL_Event e;
	while (true) {
		while (SDL_PollEvent(&e)) {
			
		}
		
		i += 0.0001;
		SDL_SetRenderDrawColor(renderer, (sin(i)+1) / 2 * 255, (sin(i) + 1) / 2 * 255, 0, 255);
		SDL_RenderClear(renderer);

		SDL_Rect rect;
		rect.x = 50;
		rect.y = 50;
		rect.w = 100;
		rect.h = 100;
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		SDL_RenderPresent(renderer);
	}
	SDL_Delay(5000);
	SDL_Quit();
	return 0;
}