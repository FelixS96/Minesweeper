#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Map.h"

//different gamestates
enum gamestate { exitgame, splash, startmen, ingame,credits,help, hidden,introd };
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
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);								//audio channel
	music = Mix_LoadMUS("music.wav");												//load file
	//no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music, -1);
	}	
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
		gamestatus = introd;				//switch to menu
		break;
	case introd:
		introduction = new intro("cut1.png", renderer);	//show credits and go back with escape
		if (introduction->m == 2) {
			delete(fullscreen);
			SDL_Delay(200);
		}
		introduction = new intro("cut2.png", renderer);	//show credits and go back with escape
		if (introduction->m == 2) {
			delete(fullscreen);
			SDL_Delay(200);
		}
		introduction = new intro("cut3.png", renderer);	//show credits and go back with escape
		if (introduction->m == 2) {
			delete(fullscreen);
			SDL_Delay(200);
		}
		introduction = new intro("cut4.png", renderer);	//show credits and go back with escape
		if (introduction->m == 2) {
			delete(fullscreen);
			SDL_Delay(200);
		}
		startmenu->mouseup = false;
		gamestatus = startmen;
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
		else if (startmenu->Gamestate == 6) {
			gamestatus = hidden;				//switch to help
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
	case hidden:
		fullscreen = new fullscreenimage("easter.png", renderer, 6);		//show help and go back with escape
		if (fullscreen->m == 2) {
			gamestatus = startmen;
			startmenu->Gamestate = 2;
			delete(fullscreen);
			SDL_Delay(200);
			startmenu->mouseup = false;
		}
		break;
	}
}


Game::~Game()
{
	Mix_FreeMusic(music);
	SDL_Quit();
}
