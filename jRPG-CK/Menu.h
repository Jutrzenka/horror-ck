#pragma once

#include <vector>
#include <string>

class Menu {
private:
    std::vector<std::string> options_; // Lista opcji menu
    int selectedIndex_;                // Aktualnie wybrana opcja

    void Render() const;               // Funkcja rysuj¹ca menu za pomoc¹ Raylib

public:
    Menu();                            // Konstruktor ustawiaj¹cy domyœlne opcje
    void Show();                       // G³ówna pêtla obs³uguj¹ca menu
};