#include "GameMap.h"
#include "raylib.h" // Do wizualizacji/oœwietlania, jeœli potrzebne
#include <random>
#include <algorithm> // std::count_if

// Konstruktor planszy - inicjalizuje wymiary
GameMap::GameMap(int width, int height)
    : width_(width), height_(height), map_(height, std::vector<Tile>(width, Tile::Wall)) {
}

// Funkcja do pocz¹tkowej inicjalizacji planszy
void GameMap::InitializeMap(float wallProbability) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            // Losowo przypisujemy œciany
            map_[y][x] = (dist(gen) < wallProbability) ? Tile::Wall : Tile::Floor;
        }
    }
}

// Funkcja do liczenia liczby œcian wokó³ danego pola
int GameMap::CountWallsAround(int x, int y) const {
    const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    const int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    int wallCount = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < width_ && ny >= 0 && ny < height_) {
            if (map_[ny][nx] == Tile::Wall) {
                ++wallCount;
            }
        }
        else {
            // Traktujemy pola poza granic¹ jako œciany
            ++wallCount;
        }
    }

    return wallCount;
}

// Symulacja automatu komórkowego
void GameMap::RunCellularAutomata(int iterations) {
    auto newMap = map_;
    for (int iter = 0; iter < iterations; ++iter) {
        for (int y = 0; y < height_; ++y) {
            for (int x = 0; x < width_; ++x) {
                int wallCount = CountWallsAround(x, y);
                if (wallCount > 4) {
                    newMap[y][x] = Tile::Wall; // Du¿o œcian - zostaje œcian¹
                }
                else if (wallCount < 4) {
                    newMap[y][x] = Tile::Floor; // Ma³o œcian - zostaje pod³og¹
                }
            }
        }
        map_ = newMap;
    }
}

// G³ówna funkcja generowania
void GameMap::Generate(int iterations, float wallProbability) {
    InitializeMap(wallProbability);
    RunCellularAutomata(iterations);
}

// Rysowanie mapy za pomoc¹ Raylib
void GameMap::Draw() const {
    const int tileSize = 20; // Rozmiar pojedynczego kafelka w pikselach
    
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            Color color = (map_[y][x] == Tile::Wall) ? DARKGRAY : LIGHTGRAY;
            DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, color);
        }
    }
}

// Debug - generator tekstowej reprezentacji planszy
std::string GameMap::ToString() const {
    std::string result;
    for (const auto& row : map_) {
        for (const auto tile : row) {
            result += (tile == Tile::Wall) ? "#" : ".";
        }
        result += '\n';
    }
    return result;
}

// Zwraca kafelek odpowiadaj¹cy pozycji w œwiecie
GameMap::Tile GameMap::GetTile(float x, float y) const {
    const int tileX = static_cast<int>(x);
    const int tileY = static_cast<int>(y);
    if (tileX < 0 || tileX >= width_ || tileY < 0 || tileY >= height_) {
        return Tile::Wall; // Poza map¹ traktujemy jako œcianê
    }
    return map_[tileY][tileX];
}