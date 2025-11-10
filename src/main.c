#include "raylib.h"
#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
    const int width = 1080;
    const int height = 720;
    const int play_height = 50;

    ///////////////////////////////////////////////////////////////////////////
    // Game State
    int player_left_score = 0;
    int player_right_score = 0;

    Rectangle paddle_left = {
        .x = 0.03f * width,
        .y = 0.5f * height,
        .width = 0.01f * width,
        .height = 0.15f * height,
    };

    Rectangle paddle_right = {
        .x = 0.97f * width,
        .y = 0.5f * height,
        .width = 0.01f * width,
        .height = 0.15f * height,
    };

    float ball_radius = 10;
    Vector2 ball_position = {
        .x = 0.5f * width,
        .y = 0.5f * height,
    };
    Vector2 ball_velocity = {
        .x = 0.0f,
        .y = 8.0f,
    };

    ///////////////////////////////////////////////////////////////////////////
    // Game Loop
    InitWindow(width, height, "Pong");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        ///////////////////////////////////////////////////////////////////////
        // Update
        if (IsKeyDown(KEY_W))
        {
            paddle_left.y = MAX(play_height, paddle_left.y - 10);
        }
        if (IsKeyDown(KEY_S))
        {
            paddle_left.y =
                MIN(height - paddle_left.height, paddle_left.y + 10);
        }

        if (IsKeyDown(KEY_UP))
        {
            paddle_right.y = MAX(play_height, paddle_right.y - 10);
        }
        if (IsKeyDown(KEY_DOWN))
        {
            paddle_right.y =
                MIN(height - paddle_left.height, paddle_right.y + 10);
        }

        if (ball_velocity.y > 0)
        {
            if (ball_position.y >= height - ball_radius)
            {
                ball_velocity.y *= -1;
                ball_position.y = height - ball_radius;
            }
        }
        else
        {
            if (ball_position.y <= play_height + ball_radius)
            {
                ball_velocity.y *= -1;
                ball_position.y = play_height + ball_radius;
            }
        }

        ball_position.x += ball_velocity.x;
        ball_position.y += ball_velocity.y;

        ///////////////////////////////////////////////////////////////////////
        // Render
        BeginDrawing();
        ClearBackground(BLACK);

        // Render Game
        DrawRectangleRec(paddle_left, WHITE);
        DrawRectangleRec(paddle_right, WHITE);
        DrawCircleV(ball_position, ball_radius, WHITE);

        // Render Header
        DrawLine(0, play_height, width, play_height, WHITE);

        char buffer[4];
        sprintf(buffer, "%d", player_left_score);
        DrawText(buffer, 100, 20, 20, WHITE);

        sprintf(buffer, "%d", player_right_score);
        DrawText(buffer, 980, 20, 20, WHITE);

        DrawText("Pong", 536, 20, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
