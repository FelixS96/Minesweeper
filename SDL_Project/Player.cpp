#include "Player.h"



Player::Player(int x, int y)
{
	
}

void Player::moveTo(int x, int y)
{
	this->xpos = 50+32+x;	//POsx Border+Middle
	this->ypos = 50+32+y;
}


Player::~Player()
{
}
