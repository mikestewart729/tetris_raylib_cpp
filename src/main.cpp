#include "../include/raylib.h"
#include "game.h"

#include <cstdlib>
#include <chrono>

double last_update_time { 0.0 };

bool EventTriggered(double interval)
{
    double current_time { GetTime() };
    if (current_time - last_update_time >= interval)
    {
        last_update_time = current_time;
        return true;
    }
    return false;
}

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
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(dark_blue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}