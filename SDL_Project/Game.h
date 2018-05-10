#pragma once
#include <SDL.h>
class Game
{
public:
	Game();
	~Game();
	static void Start();

private:
	static bool isExiting();
	static void GameLoop();

	enum GameState {Uninitialized, Splashscreen, Mainmenu, Paused, Playing, Exiting};

	static GameState _gameState;
	static GameWindow _mainwindow;
};

