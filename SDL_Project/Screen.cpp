#include <SDL.h>
#include "Screen.h"


Screen::Screen(char * WindowName, int PosX, int PosY, int Width, int Height)
{
	this->Name = WindowName;
	this->Window = SDL_CreateWindow(WindowName, PosX,PosY,Width,Height,SDL_WINDOW_SHOWN);

}

Screen::~Screen()
{
}

