#include "Map.h"
#include <raylib.h>

Map::Map()
{
    tileSize = 200;

    int temp[rows][cols] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,1,0,1,0,1,0,1,0,1,1,0,1},
        {1,0,1,0,0,1,0,0,0,1,0,0,1,0,1},
        {1,0,0,0,1,1,0,1,0,1,1,0,0,0,1},
        {1,0,1,0,0,0,0,1,0,0,0,0,1,0,1},
        {1,0,1,1,0,1,0,0,0,1,0,1,1,0,1},
        {1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
        {1,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            map[row][col] = temp[row][col];
        }
    }
}

void Map::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (map[row][col] == 1)
            {
                DrawRectangle(
                    col * tileSize,
                    row * tileSize,
                    tileSize,
                    tileSize,
                    BLUE
                );
            }
        }
    }
}

bool Map::CheckCollision(Rectangle player)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (map[row][col] == 1)
            {
                Rectangle wall = {
                    (float)(col * tileSize),
                    (float)(row * tileSize),
                    (float)tileSize,
                    (float)tileSize
                };

                if (CheckCollisionRecs(player, wall))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
