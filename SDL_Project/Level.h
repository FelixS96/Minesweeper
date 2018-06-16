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
	bool mouseup;
	//collision modes
	int collide;
public:
	SDL_Event e;						//events
	int Gamestate;						//gamestate (exitcondition)
	SDL_Renderer* renderer;				//renderer
	Level(int num);						//create map number
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	void wind(SDL_Window* wind);		//create a renderer in wind
	void Update(float deltaTime);		//repeatedly used function
	~Level();
};

