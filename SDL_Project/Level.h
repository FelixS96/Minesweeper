#pragma once
#include "SDL.h"
#include "Map.h"
#include "Player.h"
#include <SDL_image.h>
#include <string>
#include <vector>
//#include "Renderer.h"
class Level
{
private:
	
	Map* map;
	Player* player;
	bool textures;
	SDL_Texture* Texture1;
	SDL_Texture* Texture2;
	SDL_Texture* Texture3;
	SDL_Texture* Texture4;

	SDL_Texture* Texture5;
	SDL_Texture* Texture6;
	//Renderer* renderer;
	int collide;
public:
	SDL_Event e;
	int Gamestate;
	SDL_Renderer* renderer;
	Level(int num);
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	void wind(SDL_Window* wind);
	void Update(float deltaTime);
	~Level();
};

