#include "../include/raylib.h"

int main()
{
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}