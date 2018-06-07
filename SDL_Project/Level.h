#pragma once
#include "SDL.h"
#include "Map.h"
#include "Player.h"
#include "Renderer.h"
class Level
{
private:
	SDL_Event e;
	Map* map;
	Player* player;
	Renderer* renderer;
public:
	Level(int num);
	void Update(float deltaTime);
	~Level();
};

