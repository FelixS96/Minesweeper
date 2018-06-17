//#include <iostream>
//#include "Game.h"
//#include "SDL.h"
//#include "SDL_mixer.h"
/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
//#include "SDL_image.h"
//#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>

// Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
SDL_Window *screen = NULL;
//The event structure
SDL_Event event;

//The music that will be played
Mix_Music *music = NULL;

//The sound effects that will be used
Mix_Chunk *scratch = NULL;
Mix_Chunk *high = NULL;
Mix_Chunk *med = NULL;
Mix_Chunk *low = NULL;




bool init()
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}


	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	//Set up the screen
	screen = SDL_CreateWindow("Finding Home", 50, 50, 1600, 950, SDL_WINDOW_SHOWN);

	//If there was an error in setting up the screen
	if (screen == NULL)
	{
		return false;
	}
	
	//If everything initialized fine
	return true;
}

bool load_files()
{

	//Load the music
	music = Mix_LoadMUS("test/beat.wav");

	//If there was a problem loading the music
	if (music == NULL)
	{
		return false;
	}

	//Load the sound effects
	scratch = Mix_LoadWAV("test/scratch.wav");
	high = Mix_LoadWAV("test/high.wav");
	med = Mix_LoadWAV("test/medium.wav");
	low = Mix_LoadWAV("test/low.wav");

	//If there was a problem loading the sound effects
	if ((scratch == NULL) || (high == NULL) || (med == NULL) || (low == NULL))
	{
		return false;
	}

	//If everything loaded fine
	return true;
}

void clean_up()
{
	
	//Free the sound effects
	Mix_FreeChunk(scratch);
	Mix_FreeChunk(high);
	Mix_FreeChunk(med);
	Mix_FreeChunk(low);

	//Free the music
	Mix_FreeMusic(music);

	

	//Quit SDL_mixer
	Mix_CloseAudio();

	

	//Quit SDL
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Quit flag
	bool quit = false;

	//Initialize
	if (init() == false)
	{
		return 1;
	}

	//Load the files
	if (load_files() == false)
	{
		return 1;
	}

	//While the user hasn't quit
	while (quit == false)
	{
		//While there's events to handle
		while (SDL_PollEvent(&event))
		{
			//If a key was pressed
			if (event.type == SDL_KEYDOWN)
			{
				//If 1 was pressed
				if (event.key.keysym.sym == SDLK_1)
				{
					//Play the scratch effect
					if (Mix_PlayChannel(-1, scratch, 0) == -1)
					{
						return 1;
					}
				}
				//If 2 was pressed
				else if (event.key.keysym.sym == SDLK_2)
				{
					//Play the high hit effect
					if (Mix_PlayChannel(-1, high, 0) == -1)
					{
						return 1;
					}
				}
				//If 3 was pressed
				else if (event.key.keysym.sym == SDLK_3)
				{
					//Play the medium hit effect
					if (Mix_PlayChannel(-1, med, 0) == -1)
					{
						return 1;
					}
				}
				//If 4 was pressed
				else if (event.key.keysym.sym == SDLK_4)
				{
					//Play the low hit effect
					if (Mix_PlayChannel(-1, low, 0) == -1)
					{
						return 1;
					}
				}
				//If 9 was pressed
				else if (event.key.keysym.sym == SDLK_9)
				{
					//If there is no music playing
					if (Mix_PlayingMusic() == 0)
					{
						//Play the music
						if (Mix_PlayMusic(music, -1) == -1)
						{
							return 1;
						}
					}
					//If music is being played
					else
					{
						//If the music is paused
						if (Mix_PausedMusic() == 1)
						{
							//Resume the music
							Mix_ResumeMusic();
						}
						//If the music is playing
						else
						{
							//Pause the music
							Mix_PauseMusic();
						}
					}
				}
				//If 0 was pressed
				else if (event.key.keysym.sym == SDLK_0)
				{
					//Stop the music
					Mix_HaltMusic();
				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}
	}

	//Free surfaces, fonts and sounds
	//then quit SDL_mixer, SDL_ttf and SDL
	clean_up();

	return 0;
}




////mainfunction
//int main(int argc, char* argv[])
//{
//	Uint64 currentTimestamp = SDL_GetPerformanceCounter();
//	Uint64 lastTimestamp = 0; //Timestamp of previous frame
//	float deltaTime = 0; //Passed time in Seconds
//	//start a game
//	Mix_Music *music = NULL;
//	music = Mix_LoadMUS("beat.wav");
//	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
//	Mix_PlayMusic(music, -1);
//	//Game* Game1 = new Game();
//	//while (Game1->GetState() != 0) {									//while game running
//	//	lastTimestamp = currentTimestamp;
//	//	currentTimestamp = SDL_GetPerformanceCounter();
//	//	deltaTime = ((currentTimestamp - lastTimestamp) / (float)SDL_GetPerformanceFrequency());
//	//	Game1->Update(deltaTime);										//update the game
//	//}
//	return 0;
//	}

	
