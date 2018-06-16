#pragma once
#include <SDL.h>
#include "Screen.h"
#include "Level.h"
#include "Startmenu.h"
#include "fullscreenimage.h"
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
	bool once;
	int levelcode = 1;
	int GetState();
	void SetState(int State);
	void Update(float deltaTime);
	~Game();
};

