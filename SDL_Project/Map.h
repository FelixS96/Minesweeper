#pragma once
class Map
{
private:
	
public:
	int(*bgptr)[25][10] = nullptr;
	Map(int numb);
	//void createMap();
	void update(int x, int y);
	int getposdata(int x, int y);
	int getbgdata(int x, int y);
	int* mapptr = nullptr;
	int* covptr = nullptr;
	~Map();
};

