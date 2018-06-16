#include "Map.h"



Map::Map(int numb)
{
	bgptr={								//background of maps
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 },
		{ 4,3,3,3,3,3,3,3,3,3,2,1 } 
	};
	covptr = {							//cover the map
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 },
		{ 9,9,9,9,9,9,9,9,9,9,0,0 }
	};
	if (numb == 1) {
		mapptr = {							//map 1
			{ 10,10,10,10,10,10,10,10,10,10,10,10 },
			{ 10,10,10,10,10,3,3,3,10,10,10,10 },
			{ 10,10,10,1,10,10,10,10,10,10,10,10 },
			{ 10,10,10,10,10,10,3,3,1,10,10,10 },
			{ 10,10,10,1,2,10,10,10,10,10,10,10 },
			{ 10,2,10,2,2,10,10,1,10,10,10,10 },
			{ 10,10,10,10,10,10,10,10,10,10,10,10 },
			{ 10,10,4,10,10,10,10,10,10,1,10,10 },
			{ 10,10,10,10,10,10,1,10,2,10,10,10 },
			{ 10,10,10,10,2,10,2,10,3,1,10,10 },
			{ 2,10,10,10,10,10,2,10,10,10,10,10 },
			{ 2,2,10,2,10,10,2,2,10,1,10,10 },
			{ 10,10,10,1,10,10,10,10,10,10,10,10 },
			{ 10,3,3,3,10,10,10,10,10,3,10,10 },
			{ 10,10,10,10,1,10,10,10,10,10,10,10 },
			{ 10,10,10,2,2,10,2,10,1,10,10,10 },
			{ 10,10,10,10,10,10,10,10,10,3,10,10 },
			{ 10,10,10,10,1,10,2,10,10,10,10,10 },
			{ 10,10,10,2,2,10,2,10,10,1,10,10 },
			{ 10,10,10,2,10,10,10,1,10,10,10,10 },
			{ 10,10,10,1,10,10,10,10,2,1,10,10 },
			{ 10,10,10,10,10,10,10,2,2,10,10,10 },
			{ 10,10,10,10,1,10,10,10,2,10,10,10 },
			{ 10,10,10,10,10,1,10,10,10,10,10,10 },
			{ 10,10,10,10,10,19,10,10,10,10,10,10 }			
		};
	}
	else if (numb == 2) {					//map 2

	}
	else if (numb == 3) {					//map 3

	}
}
void Map::checkcoords(int x, int y)
{
	if (x == 0) {
		left = true;
	}
	if (x == 24) {
		right = true;
	}
	if (y == 0) {
		up = true;
	}
	if (y == 9) {
		down = true;
	}
}
void Map::addnumbers()
{
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 10; y++) {
			left = false;
			right = false;
			up = false;
			down = false;
			if (mapptr[x][y] == 1) {
				checkcoords(x, y);

				if (down == false) {
					if (mapptr[x][y + 1] > 9&& mapptr[x][y + 1] < 18) {
						mapptr[x][y + 1] += 1;
					}
				}
				if (up == false) {
					if (mapptr[x][y - 1] > 9&& mapptr[x][y - 1] < 18) {
						mapptr[x][y - 1] += 1;
					}
				}

				if (right == false) {
					if (mapptr[x+1][y] > 9&& mapptr[x + 1][y] < 18) {
						mapptr[x + 1][y] += 1;
					}
					if (down == false) {
						if (mapptr[x + 1][y + 1] > 9&& mapptr[x + 1][y + 1] < 18) {
							mapptr[x + 1][y + 1] += 1;
						}
					}
					if (up == false) {
						if (mapptr[x + 1][y - 1] > 9&& mapptr[x + 1][y - 1] < 18) {
							mapptr[x + 1][y - 1] += 1;
						}
					}
				}
				if (left == false) {
					if (mapptr[x - 1][y] > 9&& mapptr[x - 1][y] < 18) {
						mapptr[x - 1][y] += 1;
					}
					if (down == false) {
						if (mapptr[x - 1][y + 1] > 9&& mapptr[x - 1][y + 1] < 18) {
							mapptr[x - 1][y + 1] += 1;
						}
					}
					if (up == false) {
						if (mapptr[x - 1][y - 1] > 9&&mapptr[x - 1][y - 1] < 18) {
							mapptr[x - 1][y - 1] += 1;
						}
					}
				}
			}
		}
	}
}
void Map::checkpos(int x, int y,int xo, int yo)
{
	//int returnstate;
	if ((mapptr[x][y] == 2 || mapptr[x][y] == 3|| mapptr[x][y] == 10|| mapptr[x][y] == 4)&&covptr[x][y]==9) {
		covptr[x][y] = 10;
	}
	else if (mapptr[x][y] > 10 && mapptr[xo][yo] == 10) {
		covptr[x][y] = 10;
	}
	//return returnstate;
}

void Map::update(int x, int y)				//change
{
	left = false;
	right = false;
	up = false;
	down = false;
	checkcoords(x, y);
	//uncover under player
	if (covptr[x][y] == 9) {
		covptr[x][y] = 0;
	}
	//uncover around player 
	//uncover numbers if the player is on no number
	if (down == false) {
		checkpos(x, y + 1,x,y);
	}
	if (up == false) {
		checkpos(x, y - 1, x, y);
	}

	if (right == false) {
		checkpos(x + 1, y, x, y);
		if (down == false) {
			checkpos(x + 1, y + 1, x, y);
		}
		if (up == false) {
			checkpos(x + 1, y - 1, x, y);
		}
	}
	if (left == false) {
		checkpos(x - 1, y, x, y);
		if (down == false) {
			checkpos(x - 1, y + 1, x, y);
		}
		if (up == false) {
			checkpos(x - 1, y - 1, x, y);
		}
	}
}

int Map::getposdata(int x, int y)
{
	int returnstate;
	if (x < 0 || x>24 || y < 0 || y>11-2) {	//check for accessable area
		returnstate = 1;
	}else
	if (mapptr[x][y]== 2|| mapptr[x][y] == 3) {	//check for walls
		returnstate = 2;
	}else 
	if(mapptr[x][y]== 1) {	//check for mines
		mapptr[x][y] = 0;	//delete mine you stepped on
		if (covptr[x][y] == 11) {
			covptr[x][y] = 10;
		}
		left = false;
		right = false;
		up = false;
		down = false;
		
		checkcoords(x, y);
		//lower numbers around bom that got destroyed
		if (down == false) {
			if (mapptr[x][y + 1] > 9&& mapptr[x][y + 1] < 18) {
				mapptr[x][y + 1] -= 1;
			}
		}
		if (up == false) {
			if (mapptr[x][y - 1] > 9&&mapptr[x][y - 1]< 18) {
				mapptr[x][y - 1] -= 1;
			}
		}

		if (right == false) {
			if (mapptr[x + 1][y] > 9&&mapptr[x + 1][y]< 18) {
				mapptr[x + 1][y] -= 1;
			}
			if (down == false) {
				if (mapptr[x + 1][y + 1] > 9&&mapptr[x + 1][y + 1] < 18) {
					mapptr[x + 1][y + 1] -= 1;
				}
			}
			if (up == false) {
				if (mapptr[x + 1][y - 1] > 9&&mapptr[x + 1][y - 1] < 18) {
					mapptr[x + 1][y - 1] -= 1;
				}
			}
		}
		if (left == false) {
			if (mapptr[x - 1][y] > 9&&mapptr[x - 1][y] < 18) {
				mapptr[x - 1][y] -= 1;
			}
			if (down == false) {
				if (mapptr[x - 1][y + 1] > 9&&mapptr[x - 1][y + 1] < 18) {
					mapptr[x - 1][y + 1] -= 1;
				}
			}
			if (up == false) {
				if (mapptr[x - 1][y - 1] > 9&&mapptr[x - 1][y - 1] < 18) {
					mapptr[x - 1][y - 1] -= 1;
				}
			}
			
		}
		returnstate = 3;
	}
	else if (mapptr[x][y] == 4) {	//check for mines
		mapptr[x][y] = 0;
		returnstate = 5;
	}
	else if (mapptr[x][y] == 19) {
		returnstate = 4;
	}
	else {
		returnstate = 0;
	}
		return returnstate;
}






Map::~Map()
{
}
