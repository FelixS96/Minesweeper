#pragma once
class Map
{
public:
	Map(int numb);
	//void createMap();
	void update(int x, int y);
	int getposdata(int x, int y);
	int* bgptr = nullptr;
	int* mapptr = nullptr;
	int* covptr = nullptr;
	~Map();
};

