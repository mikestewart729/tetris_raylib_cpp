#include "../include/raylib.h"
#include "game.h"
#include "colors.h"

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

    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("resources/fonts/mecha.png", 64, 0, 0);

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

        DrawTextEx(font, "Score", {175, 315}, 18, 2, WHITE);
        DrawRectangleRounded({165, 335, 75, 30}, 0.3, 6, light_blue);

        DrawTextEx(font, "Next", {183, 395}, 18, 2, WHITE);
        DrawRectangleRounded({165, 415, 75, 80}, 0.3, 6, light_blue);

        if (game.game_over)
        {
            DrawTextEx(font, "GAME\nOVER", {178, 550}, 18, 2, WHITE);
        }

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}