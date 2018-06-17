#include "Player.h"


//create player with money
Player::Player(int x, int y, int money)
{
	this->xpos =  x;
	this->ypos =  y;
	hp = 1;
	this->money = money;
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
