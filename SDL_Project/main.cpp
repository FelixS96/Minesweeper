#include <iostream>
#include "Game.h"

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