#include "Player.h"



Player::Player(int x, int y)
{
	this->xpos = 50 + 32 + 64 * x;
	this->ypos = 50 + 32 + 64 * y;
}

void Player::moveTo(int x, int y)
{
	this->xpos = 50 + 32 + 64 * x;	//POsx Border+Middle
	this->ypos = 50 + 32 + 64 * y;
}


Player::~Player()
{
}
