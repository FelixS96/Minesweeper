#include "Level.h"
#include <iostream>
#define XSIZE 25
#define YSIZE 12
#define TEXSIZE 64
#define TOPOFFSET 30
Level::Level(int num)
{
	//create Level
	//insert Player
	//Create Textures
	map = new Map(num);	
	map->addnumbers();
	int hard = 10 / num;
	player = new Player(0,0,hard);
	
	//Gamestate running
	//textures not loaded
	this->Gamestate = 1;
	textures = false;
	finished = false;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	click = Mix_LoadWAV("click.wav");
	dead = Mix_LoadWAV("dead.wav");
	win = Mix_LoadWAV("win.wav");
	eating = Mix_LoadWAV("eating.wav");
	explosion = Mix_LoadWAV("explosion.wav");
	pause = false;
}

//how to load textures
SDL_Texture* Level::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;

}
//used while running
void Level::Update(float deltaTime, SDL_Renderer* renderer)
{
	
	if (textures == false) {								//load textures if not loaded
		Texture1 = loadTexture("bg1.png", renderer);
		Texture2 = loadTexture("bg2.png", renderer);
		Texture3 = loadTexture("bg3.png", renderer);
		Texture4 = loadTexture("bg4.png", renderer);
		Texture5 = loadTexture("mine.png", renderer);
		Texture6 = loadTexture("char.png", renderer);
		Texture7 = loadTexture("hind.png", renderer);
		Texture8 = loadTexture("hind2.png", renderer);
		Texture9 = loadTexture("cover.png", renderer);
		Texture10 = loadTexture("heart.png", renderer);
		Texture11 = loadTexture("1.png", renderer);
		Texture12 = loadTexture("2.png", renderer);
		Texture13 = loadTexture("3.png", renderer);
		Texture14 = loadTexture("4.png", renderer);
		Texture15 = loadTexture("5.png", renderer);
		Texture16 = loadTexture("6.png", renderer);
		Texture17 = loadTexture("7.png", renderer);
		Texture18 = loadTexture("8.png", renderer);
		Texture19 = loadTexture("target.png", renderer);
		Texture20 = loadTexture("minemaybe.png", renderer);
		Texture21 = loadTexture("food.png", renderer);
		Texture22 = loadTexture("coin.png", renderer);
		Texture23 = loadTexture("plus.png", renderer);
		Texture24 = loadTexture("vortex.png", renderer);
		textures = true;									//textures loaded
	}
	//target rect for rendering tasks
	SDL_Rect rect;

	//get player position
	int px = player->xpos;
	int py = player->ypos;
	//mouse position
	int mx;
	int my;
	//printf("%f", deltaTime);
	if (map->covptr[px][py] == 9) {
		map->update(px, py);
	}
	//read eventdata
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT) {				//exit button
		Gamestate=0;
	}else if (e.type == SDL_KEYDOWN) {		//keys used
		switch (e.key.keysym.sym)
		{									//different keys move the player pos
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
			break;
		case SDLK_ESCAPE:
			if (pause&&!buttondown) {
				pause = false;
				Mix_ResumeMusic();
				buttondown = true;
			}
			else if(!pause&&!buttondown) { 
				pause = true;
				Mix_PauseMusic();
				SDL_Delay(100);
				buttondown = true;
			}
			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			buttondown = false;
			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		if (e.button.button==SDL_BUTTON_LEFT&&mouseup==false) {
			if (!pause) {
				SDL_GetMouseState(&mx, &my);
				if (my < 681) {
					mx /= TEXSIZE;
					my = (my - TOPOFFSET) / TEXSIZE;
					if (map->covptr[mx][my] == 9) {
						map->covptr[mx][my] = 11;
					}
					else if (map->covptr[mx][my] == 11) {
						map->covptr[mx][my] = 9;
					}
					Mix_PlayChannel(-1, click, 0);
				}
				else if (my > 749 && my < 815 && mx>79 && mx < 145) {
					if (player->money > 1) {
						player->money -= 2;
						player->hp += 1;
					}
				}

				printf("klick %i %i", mx, my);
				mouseup = true;
			}
		}
	}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT&&mouseup==true) {
			printf("loslassen");
			mouseup = false;
		}
	}
	if (!pause) {
		if (px != player->xpos || py != player->ypos) {			//check if position changed by keydown
			collide = map->getposdata(px, py);					//check pos
			if (collide == 0) {									//if no collision
				player->moveTo(px, py);							//move player to
				map->update(px, py);							//update visible areas
			}
			else if (collide == 3) {							//check if player hit a mine
				player->moveTo(px, py);							//move player to 
				map->update(px, py);							//update visible areas
				player->hp -= 1;								//player steped on a mine and lost hp
				Mix_PlayChannel(-1, explosion, 0);
				if (player->hp == 0) {
					finished = true;
					Mix_PlayChannel(-1, dead, 0);
					Gamestate = 3;
				}
			}
			else if (collide == 5) {							//check if player hit food
				player->moveTo(px, py);							//move player to 
				map->update(px, py);							//update visible areas
				if (player->hp < 8) {
					player->hp += 1;								//player steped on food and got hp
				}
				Mix_PlayChannel(-1, eating, 0);
			}
			else if (collide == 6) {
				bool free = false;
				while (!free) {
					int randx = rand() % 25;
					int randy = rand() % 10;
					if (map->mapptr[randx][randy] == 10) {
						free = true;
						player->moveTo(randx, randy);
						map->update(randx, randy);
					}
				}
			}
			else if (collide == 4) {
				player->moveTo(px, py);
				//------------------------------------popup
				for (int x = 0; x < XSIZE; x++) {
					for (int y = 0; y < YSIZE; y++) {
						map->covptr[x][y] = 0;
					}
				}
				Mix_PlayChannel(-1, win, 0);
				finished = true;
				Gamestate = 2;
			}
		}
	}
	//set rect size
	rect.w = 64;
	rect.h = 64;
	//clear renderer
	SDL_RenderClear(renderer);
	//draw background color
	SDL_SetRenderDrawColor(renderer,229 , 218, 220, 255);
	//background
	//check each position in the map to draw the right textures
	for (int x=0; x< XSIZE; x++) {
		for (int y=0; y < YSIZE; y++) {
			int bginfo = map->bgptr[x][y];
			//set target area for background texture
			rect.x = x* TEXSIZE;
			rect.y = y* TEXSIZE + TOPOFFSET;
			if (bginfo == 3) {
				SDL_RenderCopy(renderer, Texture3, NULL, &rect);
			}
			else if (bginfo == 1) {
				SDL_RenderCopy(renderer, Texture1, NULL, &rect);
			}
			else if (bginfo == 2) {
				SDL_RenderCopy(renderer, Texture3, NULL, &rect);
				SDL_RenderCopy(renderer, Texture2, NULL, &rect);
			}else if(bginfo == 4) {
				SDL_RenderCopy(renderer, Texture4, NULL, &rect);
			}
			
		}
	}
	//content
	//check each position in the map to draw the right textures
	for (int x = 0; x< XSIZE; x++) {
		for (int y = 0; y < YSIZE; y++) {
			int mapinfo = map->mapptr[x][y];
			//set target area for content texture
			rect.x = x * TEXSIZE;
			rect.y = y * TEXSIZE + TOPOFFSET;
			if (mapinfo == 0) {
				//SDL_RenderCopy(Level::renderer, Level::Texture3, NULL, &rect);
			}
			else if (mapinfo == 1) {
				SDL_RenderCopy(renderer, Texture5, NULL, &rect);
			}
			else if (mapinfo == 2) {

				SDL_RenderCopy(renderer, Texture7, NULL, &rect);
			}
			else if (mapinfo == 3) {
				SDL_RenderCopy(renderer, Texture8, NULL, &rect);
			}
			else if (mapinfo == 4) {
				SDL_RenderCopy(renderer, Texture21, NULL, &rect);
			}
			else if (mapinfo == 11) {
				SDL_RenderCopy(renderer, Texture11, NULL, &rect);
			}
			else if (mapinfo == 12) {
				SDL_RenderCopy(renderer, Texture12, NULL, &rect);
			}
			else if (mapinfo == 13) {
				SDL_RenderCopy(renderer, Texture13, NULL, &rect);
			}
			else if (mapinfo == 14) {
				SDL_RenderCopy(renderer, Texture14, NULL, &rect);
			}
			else if (mapinfo == 15) {
				SDL_RenderCopy(renderer, Texture15, NULL, &rect);
			}
			else if (mapinfo == 16) {
				SDL_RenderCopy(renderer, Texture16, NULL, &rect);
			}
			else if (mapinfo == 17) {
				SDL_RenderCopy(renderer, Texture17, NULL, &rect);
			}
			else if (mapinfo == 18) {
				SDL_RenderCopy(renderer, Texture18, NULL, &rect);
			}
			else if (mapinfo == 19) {
				SDL_RenderCopy(renderer, Texture19, NULL, &rect);
			}
			else if (mapinfo == 5) {
				SDL_RenderCopy(renderer, Texture24, NULL, &rect);
			}
		}
	}
	//covering (visible area and numbers)
	//check each position in the map to draw the right textures
	for (int x = 0; x< XSIZE; x++) {
		for (int y = 0; y < YSIZE; y++) {
			int covinfo = map->covptr[x][y];
			//set target area for content texture
			rect.x = x * TEXSIZE;
			rect.y = y * TEXSIZE + TOPOFFSET;
			if (covinfo == 9) {
				SDL_RenderCopy(renderer, Texture9, NULL, &rect);	//some cover
			}
			else if (covinfo==11) {
				SDL_RenderCopy(renderer, Texture20, NULL, &rect);	//mine marked
			}
			else {/*clear*/ }

		}
	}
	
	//draw hearts
	for (int i = 0; i < player->hp; i++) {
		int row = 0;
		int x=i;
		if (i > 4) {
			row += 70;
			x -= 5;
		}
		rect.x = 150 + x * 70;
		rect.y = 750 + row;
		SDL_RenderCopy(renderer, Texture10, NULL, &rect);
	}
	//draw money
	for (int i = 0; i < player->money; i++) {
		int row = 0;
		int x = i;
		if (i > 4) {
			row += 70;
			x -= 5;
		}
		rect.x = 1150 + x * 70;
		rect.y = 750 + row;
		SDL_RenderCopy(renderer, Texture22, NULL, &rect);
	}
	//draw + for hearts
	rect.x = 80;
	rect.y = 750;
	SDL_RenderCopy(renderer, Texture23, NULL, &rect);
	
	//target area for player
	rect.x = player->xpos * TEXSIZE;
	rect.y = player->ypos * TEXSIZE + TOPOFFSET;
	SDL_RenderCopy(renderer, Texture6, NULL, &rect);

	//show renderer
	SDL_RenderPresent(renderer);
}



Level::~Level()
{
	Level::map = nullptr;
	Level::player = nullptr;
}
