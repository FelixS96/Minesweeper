#include <iostream>
#include "Game.h"

//mainfunction
int main(int argc, char* argv[])
{
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0; //Timestamp of previous frame
	float deltaTime = 0; //Passed time in Seconds
	//start a game
	Game* Game1 = new Game();
	while (Game1->GetState() != 0) {									//while game running
		lastTimestamp = currentTimestamp;
		currentTimestamp = SDL_GetPerformanceCounter();
		deltaTime = ((currentTimestamp - lastTimestamp) / (float)SDL_GetPerformanceFrequency());
		Game1->Update(deltaTime);										//update the game
	}
	return 0;
	}

	
