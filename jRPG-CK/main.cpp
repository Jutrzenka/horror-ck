#include "raylib.h"
#include "Menu.h"

int main() {
    // Inicjalizacja okna Raylib
    InitWindow(800, 600, "Haunted House Game");
    SetTargetFPS(60);

    // Utworzenie i wywołanie menu
    Menu menu;
    menu.Show();

    // Główna logika gry w przyszłości...
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Game will start...", 200, 300, 20, WHITE);

        EndDrawing();
    }

    // Sprzątanie
    CloseWindow();
    return 0;
}