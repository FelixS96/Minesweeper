#include <iostream>
#include "Game.h"
#include "SDL.h"



//mainfunction
int main(int argc, char* argv[])
{
	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
	Uint64 lastTimestamp = 0; //Timestamp of previous frame
	float deltaTime = 0; //Passed time in Seconds
	//start a game
	Mix_Music *music = NULL;
	music = Mix_LoadMUS("beat.wav");
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_PlayMusic(music, -1);
	Game* Game1 = new Game();
	while (Game1->GetState() != 0) {									//while game running
		lastTimestamp = currentTimestamp;
		currentTimestamp = SDL_GetPerformanceCounter();
		deltaTime = ((currentTimestamp - lastTimestamp) / (float)SDL_GetPerformanceFrequency());
		Game1->Update(deltaTime);										//update the game
	}
	return 0;
	}

	
