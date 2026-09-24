#pragma once
#include <raylib.h>
class Fish
{
public:
	Fish();
	~Fish();
	void Draw();
	bool CheckCollision();
	void DrawFishHitbox(bool isColliding);

private:
	Texture2D fish_image;
	Vector2 fish_position;
};

