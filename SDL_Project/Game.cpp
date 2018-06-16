#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"

//different gamestates
enum gamestate { exitgame, splash, startmen, ingame, help,gameover };
//start in the state ---
gamestate gamestatus = splash;
Startmenu* startmenu = new Startmenu();
Level*level = new Level(1);

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)				//initiate SDL
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//error
	}
	SDL_Window* window = SDL_CreateWindow("Minesweeper", 50, 50, 1600, 950,SDL_WINDOW_SHOWN); //1600 780 +  hud
	startmenu->wind(window);
	level->wind(window);			//draw in window
}
//get set state
int Game::GetState()
{
	return State;
}
void Game::SetState(int State)
{
	this->State = State;
}
//switch between different modes
void Game::Update(float deltaTime)
{
	//if window closed ingame
	if (level->Gamestate==0||startmenu->Gamestate==0) {	
		SetState(0);
	}
	//update active gamestate
	switch (gamestatus) {
	default:
	case splash:
		startmenu->once();
		gamestatus = startmen;
		break;
	case startmen:
		
		break;
	case ingame:
		level->Update(deltaTime);
		break;
	case help:
		break;
	case gameover:
		break;
	}
}


Game::~Game()
{
	SDL_Quit();
}
