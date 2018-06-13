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
		Texture1 = loadTexture("bg1.png", renderer);
		Texture2 = loadTexture("bg2.png", renderer);
		Texture3 = loadTexture("bg3.png", renderer);
		Texture4 = loadTexture("bg4.png", renderer);
		Texture5 = loadTexture("mine.png", renderer);
		Texture6 = loadTexture("char.png", renderer);
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
		Gamestate=0;
	}
	if (px != player->xpos || py != player->ypos) {
		collide = map->getposdata(px, py);	//check pos
		if (Level::collide == 0) {
			Level::player->moveTo(px, py);
			map->update(px, py);
		}
	}
	rect.w = 64;
	rect.h = 64;
	SDL_RenderClear(renderer);
	//update map
	SDL_SetRenderDrawColor(renderer,229 , 218, 220, 255);
	for (int x=0; x< 25; x++) {
		for (int y=0; y < 10; y++) {
			int bginfo = map->bgptr[x][y]/**map->bgptr + x * 10 + y*/;
			rect.x = x*64;
			rect.y = y*64+50;
			if (bginfo == 3) {
				SDL_RenderCopy(renderer, Texture3, NULL, &rect);
			}
			else if (bginfo == 1) {
				SDL_RenderCopy(renderer, Texture1, NULL, &rect);
			}
			else if (bginfo == 2) {
				SDL_RenderCopy(renderer, Texture3, NULL, &rect);
				SDL_RenderCopy(renderer, Texture2, NULL, &rect);
			}else
				if(bginfo == 4) {
				SDL_RenderCopy(renderer, Texture4, NULL, &rect);
			}
			
		}
	}
	for (int x = 0; x< 25; x++) {
		for (int y = 0; y < 10; y++) {
			int mapinfo = map->mapptr[x][y]/**map->bgptr + x * 10 + y*/;
			rect.x = x * 64;
			rect.y = y * 64+50;
			if (mapinfo == 0) {
				//SDL_RenderCopy(Level::renderer, Level::Texture3, NULL, &rect);
			}
			else if (mapinfo == 1) {
				SDL_RenderCopy(renderer, Texture5, NULL, &rect);
			}
			else if (mapinfo == 2) {
				//SDL_RenderCopy(Level::renderer, Level::Texture2, NULL, &rect);
			}

		}
	}
	for (int x = 0; x< 25; x++) {
		for (int y = 0; y < 10; y++) {
			int covinfo = map->covptr[x][y]/**map->bgptr + x * 10 + y*/;
			rect.x = x * 64;
			rect.y = y * 64 + 50;
			if (covinfo == 9) {
				//SDL_RenderCopy(Level::renderer, Level::Texture3, NULL, &rect); //some cover
			}
			else if (covinfo < 9 && covinfo>0) {
						//numbers
			}else{/*clear*/}

		}
	}
	rect.x = player->xpos*64;
	rect.y = player->ypos*64+50;
	SDL_RenderCopy(renderer, Texture6, NULL, &rect);
	SDL_RenderPresent(renderer);

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
