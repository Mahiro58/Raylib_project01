#include "Otter.h"
#include <raylib.h>

Otter::Otter() 
{
	image_borred = LoadTexture("images/borred_otter.png");
	player_position.x = 300.0f;
	player_position.y = 300.0f;
	otter_speed = 200.0f;
    sourceRec = { 0.0f, 0.0f, (float)image_borred.width, (float)image_borred.height };
    destRec = { player_position.x, player_position.y, 100.0f, 100.0f };
}

Vector2 Otter::GetPosition()
{
    return player_position;
}

void Otter::SetPosition(Vector2 position)
{
    player_position = position;
}

Otter::~Otter()
{
	UnloadTexture(image_borred);
}

void Otter::Draw()
{
    destRec.x = player_position.x;
    destRec.y = player_position.y;
	DrawTexturePro(image_borred, sourceRec, destRec, { 50.0f, 50.0f }, 0.0f, WHITE);
}

void Otter::Update(float deltaTime)
{
    if (IsKeyDown(KEY_W))
    {
        player_position.y -= otter_speed * deltaTime;
    }

    if (IsKeyDown(KEY_S))
    {
        player_position.y += otter_speed * deltaTime;
    }

    if (IsKeyDown(KEY_A))
    {
        player_position.x -= otter_speed * deltaTime;
    }

    if (IsKeyDown(KEY_D))
    {
        player_position.x += otter_speed * deltaTime;
    }
}

Rectangle Otter::GetRect()
{
    return {player_position.x - 50.0f, player_position.y - 50.0f, 100.0f, 100.0f};
}

void Otter::DrawHitbox(bool isColliding)
{
    Color outlineColor = isColliding ? RED : BLACK;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}