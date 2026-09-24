#include "Fish.h"
#include <raylib.h>

Fish::Fish()
{
	fish_image = LoadTexture("");
	fish_position.x = 500.0f;
	fish_position.y = 500.0f;
}

Fish::~Fish()
{
	UnloadTexture(fish_image);
}

void Fish::Draw()
{

}