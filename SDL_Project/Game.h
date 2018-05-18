#pragma once
#include <SDL.h>
#include "Screen.h"
class Game
{
private:
	int State = 1;
public:
	SDL_Event e;
	Screen* screen;
	Game();
	int GetState();
	void SetState(int State);
	void Update(float deltaTime);

	~Game();
};

