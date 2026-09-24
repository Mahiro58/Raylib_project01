#include "raylib.h"
#include "Otter.h"
#include "Map.h"
#include "Fish.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Borred Packman");

    SetTargetFPS(60);

    Otter otter;
    Fish fish;
    Map map;
    Rectangle obstacle = Rectangle(600, 200, 100, 10);

    Camera2D camera = { 0 };

    camera.target = otter.GetPosition();
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        Vector2 oldPosition = otter.GetPosition();

        otter.Update(deltaTime);

        if (map.CheckCollision(otter.GetRect()))
        {
            otter.SetPosition(oldPosition);
        }

        bool isColliding = CheckCollisionRecs(fish.GetRect(), otter.GetRect());

        camera.target = otter.GetPosition();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        map.Draw();

        //DrawRectangleLinesEx(obstacle, 5, BLACK);
        otter.Draw();
        fish.Draw();

        otter.DrawHitbox(isColliding);
        fish.FishHitbox(isColliding);

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}