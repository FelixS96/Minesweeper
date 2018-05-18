#include "Level.h"
#include <iostream>



Level::Level()
{
	//create Level
	//insert Player
	Level::map = new Map();
	Level::player = new Player(0,0);
	Level::renderer = new Renderer(/*fenster*/);
}

void Level::Update(float deltaTime)
{
	printf("%f", deltaTime);
	SDL_PollEvent(&e);
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		default:
			break;
		case SDLK_w:
			break;
		case SDLK_a:
			break;
		case SDLK_s:
			break;
		case SDLK_d:
			break;
		}
	}
	//update
	//render
	
	
}


Level::~Level()
{
}
