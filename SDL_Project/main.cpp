#include <iostream>
#include "Game.h"

//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <string>
//
////The window we'll be rendering to
//SDL_Window* gWindow = NULL;
//
////The window renderer
//SDL_Renderer* gRenderer = NULL;
//
////Current displayed texture
//SDL_Texture* gTexture = NULL;

int main(int argc, char* argv[])
{
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0; //Timestamp of previous frame
	float deltaTime = 0; //Passed time in Seconds

	Game* Game1 = new Game();
	while (Game1->GetState() != 0) {
		lastTimestamp = currentTimestamp;
		currentTimestamp = SDL_GetPerformanceCounter();
		deltaTime = ((currentTimestamp - lastTimestamp) / (float)SDL_GetPerformanceFrequency());
		Game1->Update(deltaTime);
	}
	return 0;
	}

	
