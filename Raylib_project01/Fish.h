#pragma once
#include <raylib.h>
class Fish
{
public:
	Fish();
	~Fish();
	void Draw();
	bool CheckCollision();
	void FishHitbox(bool isColliding);
	Rectangle GetRect();

private:
	Texture2D fish_image;
	Vector2 fish_position;
	Rectangle sourceRec;
	Rectangle destRec;
};

