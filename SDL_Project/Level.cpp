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
	int px = player->xpos;
	int py = player->ypos;
	printf("%f", deltaTime);
	SDL_PollEvent(&e);
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		default:
			break;
		case SDLK_w:
			py -= 1;
			break;
		case SDLK_a:
			px -= 1;
			break;
		case SDLK_s:
			py += 1;
			break;
		case SDLK_d:
			px += 1;
			/*Level::collide = map->getposdata(player->xpos+1, player->ypos);
			Level::player->moveTo(player->xpos +1, player->ypos);*/
			break;
		}
	}
	Level::collide = map->getposdata(px, py);	//check pos
	if (Level::collide == 0) {
		Level::player->moveTo(px, py);
		map->update(px, py);
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
	Level::map = nullptr;
	Level::player = nullptr;
	Level::renderer = nullptr;
}
