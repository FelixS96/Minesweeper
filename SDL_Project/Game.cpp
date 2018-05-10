#include "Game.h"


SDL_Event e;
Game::Game()
{
}


Game::~Game()
{
}

void Game::Start()
{
	if (_gameState != Uninitialized) {
		return;
	}
	while (!isExiting()) {
		GameLoop();
	}
	_mainwindow.Close();
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting) {
		return true;
	}else {
		return false;
	}
}

void Game::GameLoop()
{
	
}
