#include "../include/raylib.h"
#include "game.h"

#include <cstdlib>
#include <chrono>

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    Color dark_blue { 44, 44, 127, 255 };

    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);

    Game game { Game() };

    while (!WindowShouldClose())
    {
        game.HandleInput();

        BeginDrawing();
        ClearBackground(dark_blue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}