#include "Player.h"


//create player
Player::Player(int x, int y)
{
	this->xpos =  x;
	this->ypos =  y;
	hp = 1;
	money = 10;
}
//change position
void Player::moveTo(int x, int y)
{
	this->xpos =  x;	
	this->ypos = y;
}


Player::~Player()
{
}
