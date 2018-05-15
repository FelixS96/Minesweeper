#include <iostream>
#include "Game.h"
#include "Screen.h"



Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//error
	}
	Screen MainWindow = Screen("Minesweeper",50,50,640,480);
	
}

int Game::GetState()
{

	return State;
}

void Game::SetState(int State)
{
	this->State = State;
}

void Game::Update()
{
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT) {
		SetState(0);
	}
}


Game::~Game()
{
	SDL_Quit();
}
