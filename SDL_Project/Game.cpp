#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"

//different gamestates
enum gamestate { exitgame, splash, startmen, ingame,credits,help, gameover };
//start in the state ---
gamestate gamestatus= splash;
Startmenu* startmenu = new Startmenu();


Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)												//initiate SDL
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//error
	}
	screen = SDL_CreateWindow("Finding Home", 50, 50, 1600, 950,SDL_WINDOW_SHOWN); //1600 780 +  hud
	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	once = false;
	music = Mix_LoadMUS("beat.wav");
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_PlayMusic(music, -1);
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
	if (level != nullptr) {
		if (level->Gamestate == 0 ) {
			SetState(0);
		}
	}
	if (startmenu->Gamestate==0) {	
		SetState(0);
	}
	//update active gamestate
	switch (gamestatus) {
	default:
	case splash:
		startmenu->once(renderer);
		SDL_Delay(200);
		startmenu->mouseup = false;
		gamestatus = startmen;				//switch to menu
		break;
	case startmen:
		startmenu->update(renderer);
		levelcode = startmenu->selected;	//get levelcode to create the right level
		if (startmenu->Gamestate == 3) {
			gamestatus = ingame;			//switch to ingame
		}
		else if (startmenu->Gamestate == 4) {
			gamestatus = credits;			//switch to credits
		}
		else if (startmenu->Gamestate == 5) {
			gamestatus = help;				//switch to help
		}
		break;
	case ingame:
		if (!once) {		//create level just once
			level = new Level(levelcode);
			once = true;
			startmenu->Gamestate = 2;
		}
		level->Update(deltaTime, renderer);	//play a level
		if (level->finished == true) {
			SDL_Delay(5000);
			delete(level);
			level = nullptr;
			once = false;
			gamestatus = startmen;			//back to menu
			startmenu->mouseup = false;
		}
		break;
	case credits:
		fullscreen = new fullscreenimage("credits.png", renderer,4);	//show credits and go back with escape
		if (fullscreen->m == 2) {
			gamestatus = startmen;
			startmenu->Gamestate = 2;
			delete(fullscreen);
			SDL_Delay(200);
			startmenu->mouseup = false;
		}
		break;
	case help:
		fullscreen = new fullscreenimage("help.png", renderer, 5);		//show help and go back with escape
		if (fullscreen->m == 2) {
			gamestatus = startmen;
			startmenu->Gamestate = 2;
			delete(fullscreen);
			SDL_Delay(200);
			startmenu->mouseup = false;
		}
		break;
	case gameover:
		break;
	}
}


Game::~Game()
{
	SDL_Quit();
}
