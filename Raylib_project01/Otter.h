#pragma once
#include <raylib.h>
class Otter
{
public: 
	Otter();
	~Otter();
	void Draw();
	void Update(float deltaTime);
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	Vector2 GetPosition();
	void SetPosition(Vector2 position);

private: 
	Texture2D image_borred;
	Texture2D image_eating;
	Vector2 player_position;
	float otter_speed;
	Rectangle sourceRec;
	Rectangle destRec;
};

