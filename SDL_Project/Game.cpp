#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Level.h"


enum gamestate { exitgame, splash, startmenu, ingame, gameover };
gamestate gamestatus = ingame;
Level*level = new Level();
Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//error
	}
	Game::screen = new Screen("Minesweeper",50,50,640,480);
	
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
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT) {
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
