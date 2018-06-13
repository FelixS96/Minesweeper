#pragma once
#include <SDL.h>
#include "Screen.h"
#include "Level.h"
class Game
{
private:
	int State = 1;
public:

	SDL_Event e;
	SDL_Window* screen;
	Game();
	int GetState();
	void SetState(int State);
	void Update(float deltaTime);
	void levelst();
	~Game();
};

