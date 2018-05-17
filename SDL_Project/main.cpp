#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* Game1 = new Game();
	while (Game1->GetState() != 0) {
		Game1->Update();
	}
	return 0;
}