#include "raylib.h"
#include "Otter.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Borred Packman");

    SetTargetFPS(60);

    Otter otter;
    Rectangle obstacle = Rectangle(600, 200, 200, 175);
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        otter.Update(deltaTime);
        bool isColliding = CheckCollisionRecs(otter.GetRect(), obstacle);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleLinesEx(obstacle, 5, BLACK);
        otter.Draw();

        otter.DrawHitbox(isColliding);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}