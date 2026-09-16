#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Player Movement");

    SetTargetFPS(60);

    float playerX = 400;
    float playerY = 225;

    float speed = 200.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // UPDATE

        if (IsKeyDown(KEY_W))
        {
            playerY -= speed * deltaTime;
        }

        if (IsKeyDown(KEY_S))
        {
            playerY += speed * deltaTime;
        }

        if (IsKeyDown(KEY_A))
        {
            playerX -= speed * deltaTime;
        }

        if (IsKeyDown(KEY_D))
        {
            playerX += speed * deltaTime;
        }


        // DRAW

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(
            static_cast<int>(playerX),
            static_cast<int>(playerY),
            25,
            BLUE
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}