#include "Level.h"
#include <iostream>


//SDL_Texture* loadTexture(std::string path);
Level::Level(int num)
{
	//create Level
	//insert Player
	Level::map = new Map(num);
	Level::player = new Player(0,0);
	Level::Texture1 = NULL;
	Level::Texture2 = NULL;
	Level::Texture3 = NULL;
	Level::Texture4 = NULL;
	Level::Texture5 = NULL;
	int bg[25][10] = {
	{ 0,1,3,0,0,0,0,0,0,0 },
	{ 1,0,1,0,0,0,0,0,0,0 },
	{ 3,0,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,1,2,0,0,0,0,0,0 },
	{ 0,2,2,2,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,1,0,2,0,0,0 },
	{ 0,0,0,2,2,0,0,1,0,0 },
	{ 2,0,0,0,2,0,0,0,0,0 },
	{ 2,2,2,0,2,2,0,1,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,2,2,2,0,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,2,0,0,0,0,0 },
	{ 0,0,2,2,2,0,0,1,0,0 },
	{ 0,0,2,0,0,1,0,0,0,0 },
	{ 0,0,1,0,0,0,2,1,0,0 },
	{ 0,0,0,0,0,2,2,0,1,0 },
	{ 0,0,0,1,0,0,2,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
	};
	bgptr = &bg;
	SDL_SetRenderDrawColor(Level::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	this->Gamestate = 1;
	textures = false;
	
	
}


void Level::wind(SDL_Window * wind)
{
	Level::renderer = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Level::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;

}

void Level::Update(float deltaTime)
{
	if (textures == false) {
		Level::Texture1 = loadTexture("bg1.png", Level::renderer);
		Level::Texture2 = loadTexture("bg2.png", Level::renderer);
		Level::Texture3 = loadTexture("bg3.png", Level::renderer);
		Level::Texture4 = loadTexture("bg4.png", Level::renderer);
		Level::Texture5 = loadTexture("mine.png", Level::renderer);
		textures = true;
	}
	SDL_Rect rect;
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
	}else
	if (e.type == SDL_QUIT) {
		Level::Gamestate=0;
	}
	Level::collide = map->getposdata(px, py);	//check pos
	if (Level::collide == 0) {
		Level::player->moveTo(px, py);
		map->update(px, py);
	}
	rect.w = 64;
	rect.h = 64;
	SDL_RenderClear(Level::renderer);
	//update map
	for (int x=0; x< 25; x++) {
		for (int y=0; y < 10; y++) {
			int bginfo = *map->bgptr[x][y]/**map->bgptr + x * 10 + y*/;
			rect.x = 50+x*64;
			rect.y = 50+y*64;
			if (bginfo == 0) {

			}
			else if (bginfo == 1) {
				SDL_RenderCopy(Level::renderer, Level::Texture1, NULL, &rect);
			}
			else if (bginfo == 2) {
				SDL_RenderCopy(Level::renderer, Level::Texture2, NULL, &rect);
			}
			
		}
	}
	SDL_RenderPresent(Level::renderer);

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
