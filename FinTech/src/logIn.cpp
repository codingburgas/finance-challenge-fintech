#include "pch.h"

int main(void)
{
    const int screenWidth = 1080;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "FinTech");

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}