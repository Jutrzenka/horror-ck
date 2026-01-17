#include "Menu.h"
#include "raylib.h"

// Konstruktor - ustawia opcje menu i domyœlnie wybran¹ opcjê
Menu::Menu()
    : options_{ "Start Game", "Exit" }, selectedIndex_(0) {
}

// Funkcja renderuj¹ca menu
void Menu::Render() const {
    ClearBackground(BLACK);
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Wyœwietlenie tytu³u
    DrawText("Haunted House", screenWidth / 2 - MeasureText("Haunted House", 40) / 2, 50, 40, DARKGRAY);

    // Wyœwietlenie opcji menu
    for (size_t i = 0; i < options_.size(); i++) {
        const Color color = (i == selectedIndex_) ? YELLOW : LIGHTGRAY;
        const int textWidth = MeasureText(options_[i].c_str(), 20);
        DrawText(options_[i].c_str(), screenWidth / 2 - textWidth / 2, 150 + i * 30, 20, color);
    }
}

// Funkcja obs³uguj¹ca pêtlê menu
void Menu::Show() {
    while (!WindowShouldClose()) {
        // Obs³uga wejœcia (W górê, S dó³, Enter zatwierdzenie)
        if (IsKeyPressed(KEY_W)) selectedIndex_ = (selectedIndex_ - 1 + options_.size()) % options_.size();
        if (IsKeyPressed(KEY_S)) selectedIndex_ = (selectedIndex_ + 1) % options_.size();

        // Zatwierdzenie opcji
        if (IsKeyPressed(KEY_ENTER)) {
            if (selectedIndex_ == 0) {
                // Rozpocznij grê
                break;
            }
            else if (selectedIndex_ == 1) {
                // Wyjœcie
                CloseWindow();
                return;
            }
        }

        // Rysowanie menu
        BeginDrawing();
        Render();
        EndDrawing();
    }
}