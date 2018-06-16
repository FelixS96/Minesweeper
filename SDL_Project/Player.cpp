#include "Player.h"



Player::Player(int x, int y)
{
	this->xpos =  x;
	this->ypos =  y;
	hp = 1;
	money = 10;
}

void Player::moveTo(int x, int y)
{
	this->xpos =  x;	//POsx Border+Middle
	this->ypos = y;
}


Player::~Player()
{
}
