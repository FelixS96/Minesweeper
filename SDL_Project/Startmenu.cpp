#include "Startmenu.h"


//load texture with path into renderer
SDL_Texture * Startmenu::loadTexture(std::string path, SDL_Renderer * renderer)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}


Startmenu::Startmenu()
{
	this->Gamestate = 1;
	textures = false;
}

//start with splashscreen when starting the programm
void Startmenu::once(SDL_Renderer* renderer)
{
	while (Gamestate == 1) {
		if (textures == false) {				
			Texture1 = loadTexture("title.png", renderer);		//load screen
			textures = true;
		}
		//target rect for rendering tasks
		SDL_Rect rect;
		//set rect size
		rect.w = 1600;
		rect.h = 950;
		rect.x = 0;
		rect.y = 0;
		//clear renderer
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Texture1, NULL, &rect);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {						//exit button
			Gamestate = 0;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {		//clicked to proceed to menu
			if (e.button.button == SDL_BUTTON_LEFT && mouseup == false) {
				Gamestate = 2;
				textures = false;
				mouseup = true;
			}
		}
	}
}

void Startmenu::update(SDL_Renderer* renderer)
{
	//mouse coordinates
	int mx;
	int my;
	while (Gamestate == 2) {
		if (textures == false) {
			Texture2 = loadTexture("menu.png", renderer);
			textures = true;
		}
		//target rect for rendering tasks
		SDL_Rect rect;
		//set rect size
		rect.w = 1600;
		rect.h = 950;
		rect.x = 0;
		rect.y = 0;
		//clear renderer
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Texture2, NULL, &rect);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {				//exit button
			Gamestate = 0;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {								//mousebutton down
			if (e.button.button == SDL_BUTTON_LEFT && mouseup == false) {		//register left click once
				SDL_GetMouseState(&mx, &my);
				if (mx > 730 && mx < 870 && my>300 && my < 350) {				//Level 1 Button
					printf("Level 1");
					mouseup = true;												//prevent multiple clicks
					Gamestate = 3;
					selected = 1;												//selected Level
					SDL_RenderClear(renderer);
				}else if (mx > 730 && mx < 870 && my>400 && my < 450) {			//Level 2 Button
					printf("Level 2");
					mouseup = true;
					Gamestate = 3;
					selected = 2;
					SDL_RenderClear(renderer);
				}
				else if (mx > 730 && mx < 870 && my>500 && my < 550) {			//Level 3 Button
					printf("Level 3");
					mouseup = true;
					Gamestate = 3;
					selected = 3;
					SDL_RenderClear(renderer);
				}
				else if (mx > 730 && mx < 870 && my>600 && my < 650) {			//Credits Button
					printf("Credits");
					mouseup = true;
					Gamestate = 4;
					selected = 0;
					SDL_RenderClear(renderer);
				}
				else if (mx > 750 && mx < 850 && my>700 && my < 750) {			//help Button
					printf("help");
					mouseup = true;
					Gamestate = 5;
					selected = 0;
					SDL_RenderClear(renderer);
				}
			}
		}
	}
}


Startmenu::~Startmenu()
{
}
