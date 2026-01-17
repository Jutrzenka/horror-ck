#include "raylib.h"

// Ten plik to tylko punkt wejścia - tu nie powinno być logiki gry, 
// jedynie inicjalizacja pętli.

int main() {
    // 1. Konfiguracja okna (część techniczna)
    InitWindow(800, 600, "JRPG Portable Test");
    SetTargetFPS(60);

    // 2. Główna pętla
    while (!WindowShouldClose()) {

        // Tutaj w przyszłości będzie: game.update();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Tutaj w przyszłości będzie: game.draw();
        DrawText("Projekt przenosny dziala!", 190, 200, 20, LIGHTGRAY);
        DrawText("Mozesz skopiowac caly folder na pendrive.", 150, 240, 20, DARKGRAY);

        EndDrawing();
    }

    // 3. Sprzątanie
    CloseWindow();

    return 0;
}