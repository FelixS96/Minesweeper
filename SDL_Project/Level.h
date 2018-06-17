#pragma once
#include "SDL.h"
#include "Map.h"
#include "Player.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <vector>
#include <math.h>
class Level
{
private:
	Map* map;					//map to draw
	Player* player;				//player to draw
	bool textures;				//are textures loaded
	//textures
	SDL_Texture* Texture1;
	SDL_Texture* Texture2;
	SDL_Texture* Texture3;
	SDL_Texture* Texture4;

	SDL_Texture* Texture5;
	SDL_Texture* Texture6;

	SDL_Texture* Texture7; 
	SDL_Texture* Texture8; 
	SDL_Texture* Texture9;
	SDL_Texture* Texture10;
	SDL_Texture* Texture11;
	SDL_Texture* Texture12;
	SDL_Texture* Texture13;
	SDL_Texture* Texture14;
	SDL_Texture* Texture15;
	SDL_Texture* Texture16;
	SDL_Texture* Texture17;
	SDL_Texture* Texture18;
	SDL_Texture* Texture19;
	SDL_Texture* Texture20;
	SDL_Texture* Texture21;
	SDL_Texture* Texture22;
	SDL_Texture* Texture23;
	SDL_Texture* Texture24;
	Mix_Chunk *click = NULL;
	Mix_Chunk *dead = NULL;
	Mix_Chunk *win = NULL;
	Mix_Chunk *eating = NULL;
	Mix_Chunk *explosion = NULL;
	bool pause;
	bool mouseup;
	bool buttondown;
	SDL_Event e;				//events
	//collision modes
	int collide;
public:
	bool finished;						//is the lvl won
	int Gamestate;						//gamestate (exitcondition)
	Level(int num);						//create map number
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	void Update(float deltaTime,SDL_Renderer* renderer);		//repeatedly used function
	~Level();
};

