#pragma once
#include <SDL.h>
class Game
{
private:
	int State = 1;
	SDL_Event e;
public:
	Game();
	int GetState();
	void SetState(int State);
	void Update();

	~Game();
};

