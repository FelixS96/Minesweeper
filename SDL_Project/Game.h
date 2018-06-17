#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "Screen.h"
#include "Level.h"
#include "Startmenu.h"
#include "fullscreenimage.h"
#include <iostream>
#include <string>
class Game
{
private:
	int State = 1;
public:

	//SDL_Event e;
	SDL_Window* screen;
	SDL_Renderer* renderer;
	fullscreenimage * fullscreen;
	Game();
	Level* level = nullptr;
	Mix_Music *music = NULL;
	Mix_Chunk *click = NULL;
	Mix_Chunk *dead = NULL;
	Mix_Chunk *win = NULL;
	Mix_Chunk *eat = NULL;
	Mix_Chunk *explosion = NULL;
	bool once;
	int levelcode = 1;
	int GetState();
	void SetState(int State);
	void Update(float deltaTime);
	~Game();
};

