#include "../include/raylib.h"
#include "blocks.cpp"
#include "grid.h"

int main()
{
    Color dark_blue { 44, 44, 127, 255 };

    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);

    Grid grid { Grid() };
    grid.Print();

    OBlock block = OBlock();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(dark_blue);

        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}