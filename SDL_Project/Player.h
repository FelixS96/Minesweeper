#pragma once
class Player
{

public:
	Player(int x, int y,int money);
	void moveTo(int x, int y);
	int xpos;
	int ypos;
	int hp;
	int money;
	~Player();
};

