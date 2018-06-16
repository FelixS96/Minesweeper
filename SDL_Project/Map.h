#pragma once
#include <vector>
class Map
{
private:
	
public:
	std::vector<std::vector<int>> bgptr;
	std::vector<std::vector<int>> mapptr;
	std::vector<std::vector<int>> covptr;
	Map(int numb);
	//void createMap();
	void update(int x, int y);
	int getposdata(int x, int y);
	void checkpos(int x, int y, int xo, int yo);
	void checkcoords(int x, int y);
	void addnumbers();
	bool left;
	bool right;
	bool up;
	bool down;

	~Map();
};

