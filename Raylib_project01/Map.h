#pragma once
#include <raylib.h>
class Map
{
public:
	Map();
	void Draw();
	bool CheckCollision(Rectangle player);

private:
	static const int rows = 10;
	static const int cols = 15;

	int map[rows][cols];

	int tileSize;
};

