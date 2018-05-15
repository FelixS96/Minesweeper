#pragma once
#include <SDL.h>
class Screen
{
private:

public:
	SDL_Window * Window;
	char* Name;
	Screen(char* WindowName, int PosX, int PosY, int Width, int Height);
	~Screen();
};

