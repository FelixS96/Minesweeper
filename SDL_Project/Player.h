#pragma once
class Player
{

public:
	Player(int x, int y);
	void moveTo(int x, int y);
	int xpos;
	int ypos;
	~Player();
};

