#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"


enum gamestate { exitgame, splash, startmenu, ingame, gameover };
gamestate gamestatus = ingame;
Level*level = new Level(1);
Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//error
	}
	//Game::screen = new Screen("Minesweeper",50,50,1900,800);	
	SDL_Window* window = SDL_CreateWindow("Minesweeper", 50, 50, 1600, 850,SDL_WINDOW_SHOWN); //1600 640 +  hud
	//Game::screen = window;
	level->wind(window);
}

int Game::GetState()
{
	return State;
}
void Game::SetState(int State)
{
	this->State = State;
}

void Game::Update(float deltaTime)
{
	
	if (level->Gamestate==0) {
		SetState(0);
	}
	switch (gamestatus) {
	default:
	case splash:
		break;
	case startmenu:
		break;
	case ingame:
		level->Update(deltaTime);
		break;
	case gameover:
		break;
	}
}


Game::~Game()
{
	SDL_Quit();
}
