#include "Player.h"



Player::Player(int x, int y)
{
	this->xpos =  x;
	this->ypos =  y;
}

void Player::moveTo(int x, int y)
{
	this->xpos =  x;	//POsx Border+Middle
	this->ypos = y;
}


Player::~Player()
{
}
