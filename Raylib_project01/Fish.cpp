#include "Fish.h"
#include <raylib.h>

Fish::Fish()
{
	fish_image = LoadTexture("images/fish01.png");
	fish_position.x = 600.0f;
	fish_position.y = 600.0f;
	sourceRec = { 0.0f, 0.0f, (float)fish_image.width, (float)fish_image.height };
	destRec = { fish_position.x, fish_position.y, 200.0f, 200.0f };
}

Fish::~Fish()
{
	UnloadTexture(fish_image);
}

void Fish::Draw()
{
	destRec.x = fish_position.x;
	destRec.y = fish_position.y;
	DrawTexturePro(fish_image, sourceRec, destRec, { 50.0f, 50.0f }, 0.0f, WHITE);
}

Rectangle Fish::GetRect()
{
	return { fish_position.x, fish_position.y, 100.0f, 100.0f };
}

void Fish::FishHitbox(bool isColliding)
{
	Color outlineColor = isColliding ? RED : BLACK;
	DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}