#include "raylib.h"
#include "Menu.h"
#include "GameMap.h"
#include "Player.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Haunted House: Procedural Game");
    SetTargetFPS(60);

    // Wyświetlenie menu
    Menu menu;
    menu.Show();

    // Generowanie planszy
    GameMap gameMap(40, 30); // Proceduralna plansza 40x30
    gameMap.Generate();

    // Inicjalizacja gracza
    Player player(&gameMap, { 10.f, 10.f }); // Startowa pozycja gracza

    // Główna pętla gry
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Aktualizacja gracza
        player.Update(deltaTime);

        // Logika rysowania
        BeginDrawing();
        ClearBackground(BLACK);

        // Rysowanie mapy
        gameMap.Draw();

        // Rysowanie gracza
        Vector2 playerPos = player.GetPosition();
        DrawCircle((int)(playerPos.x * 20), (int)(playerPos.y * 20), 10, RED); // Rozmiar gracza

        EndDrawing();
    }

    CloseWindow();
    return 0;
}