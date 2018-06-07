#include "Level.h"
#include <iostream>



Level::Level(int num)
{
	//create Level
	//insert Player
	Level::map = new Map(1);
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
			//check pos
			
			Level::player->moveTo(player->xpos, player->ypos - 1);
			//direction
			break;
		case SDLK_a:
			Level::player->moveTo(player->xpos -1 , player->ypos);
			break;
		case SDLK_s:
			Level::player->moveTo(player->xpos, player->ypos + 1);
			break;
		case SDLK_d:
			Level::player->moveTo(player->xpos +1, player->ypos);
			break;
		}
	}
	
	//update map
	
	//render
	//draw map
	//draw numbers
	//draw cover
	//draw player
	
	
}


Level::~Level()
{
}
