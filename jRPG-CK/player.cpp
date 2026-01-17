#include "Player.h"

// Konstruktor otrzymuje wskaŸnik na mapê i ustawia pocz¹tkow¹ pozycjê
Player::Player(GameMap* mapRef, Vector2 startPosition)
    : position_(startPosition), speed_(100.0f), mapRef_(mapRef) {
}

// Funkcja obs³uguj¹ca sterowanie gracza
void Player::Update(float deltaTime) {
    Vector2 move = { 0 };

    // Obs³uga klawiszy W, A, S, D
    if (IsKeyDown(KEY_W)) move.y -= 1;
    if (IsKeyDown(KEY_S)) move.y += 1;
    if (IsKeyDown(KEY_A)) move.x -= 1;
    if (IsKeyDown(KEY_D)) move.x += 1;

    // Normalizacja wektora poruszania
    if (move.x != 0 || move.y != 0) {
        float length = sqrtf(move.x * move.x + move.y * move.y);
        move.x = (move.x / length) * speed_ * deltaTime;
        move.y = (move.y / length) * speed_ * deltaTime;

        // Sprawdzanie kolizji osobno dla osi X i Y
        Vector2 newPositionX = { position_.x + move.x, position_.y };
        Vector2 newPositionY = { position_.x, position_.y + move.y };
        
        // Próba ruchu w osi X
        if (mapRef_->GetTile(newPositionX.x, newPositionX.y) == GameMap::Tile::Floor) {
            position_.x = newPositionX.x;
        }
        
        // Próba ruchu w osi Y
        if (mapRef_->GetTile(newPositionY.x, newPositionY.y) == GameMap::Tile::Floor) {
            position_.y = newPositionY.y;
        }
    }

    // Obs³uga klawiszy I, O, P (na razie nic nie robi¹)
    if (IsKeyPressed(KEY_I) || IsKeyPressed(KEY_O) || IsKeyPressed(KEY_P)) {
        // Tymczasowo nic, zostawiamy miejsce na przysz³oœæ
    }
}

Vector2 Player::GetPosition() const {
    return position_;
}