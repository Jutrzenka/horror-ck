#pragma once

#include "raylib.h" // Tylko do zewnêtrznego typu Vector2 (optymalizacja)
#include "GameMap.h"

class Player {
private:
    Vector2 position_;    // Pozycja gracza
    const float speed_;   // Prêdkoœæ poruszania
    GameMap* mapRef_;     // WskaŸnik na mapê (nie zmienia mapy, dostêp tylko readonly)

public:
    explicit Player(GameMap* mapRef, Vector2 startPosition = { 1, 1 }); // Konstruktor
    void Update(float deltaTime); // Metoda obs³uguj¹ca wejœcia u¿ytkownika
    Vector2 GetPosition() const; // Getter pozycji gracza (readonly)
};