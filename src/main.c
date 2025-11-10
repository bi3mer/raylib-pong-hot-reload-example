#include "raylib.h"
#include <stdio.h>

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // Game State
    int player_left_score = 0;
    int player_right_score = 0;

    Rectangle paddle_left = {
        .x = 0.1f,
        .y = 0.5f,
        .width = 0.05f,
        .height = 0.2f,
    };

    Rectangle paddle_right = {
        .x = 0.9f,
        .y = 0.5f,
        .width = 0.05f,
        .height = 0.2f,
    };

    float ball_radius = 0.1f;
    Vector2 ball_position = {
        .x = 0.5f,
        .y = 0.5f,
    };
    Vector2 ball_velocity = {
        .x = 1.0f,
        .y = 0.0f,
    };

    ///////////////////////////////////////////////////////////////////////////
    // Raylib
    const int width = 1080;
    const int height = 720;

    InitWindow(width, height, "Raylib Template");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        char buffer[4];
        sprintf(buffer, "%d", player_left_score);
        DrawText(buffer, 100, 20, 20, WHITE);

        sprintf(buffer, "%d", player_right_score);
        DrawText(buffer, 980, 20, 20, WHITE);

        DrawText("Pong", width / 2, 20, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
