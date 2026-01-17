#pragma once

#include <vector>
#include <string>

class GameMap {
public:
    enum class Tile { Wall, Floor }; // Typ definiuj¹cy œciany i pod³ogi

private:
    std::vector<std::vector<Tile>> map_; // Dwuwymiarowy wektor reprezentuj¹cy planszê
    int width_, height_;                 // Wymiary planszy

    void InitializeMap(float wallProbability); // Inicjalizacja losowej planszy
    void RunCellularAutomata(int iterations);  // Symulacja automatu komórkowego
    int CountWallsAround(int x, int y) const;  // Funkcja pomocnicza do liczenia s¹siadów

public:
    GameMap(int width, int height);          // Konstruktor klasy
    void Generate(int iterations = 5, float wallProbability = 0.45f);
    void Draw() const; // NOWA METODA

    // Dostêp do mapy (readonly)
    const std::vector<std::vector<Tile>>& GetMap() const { return map_; }
    std::string ToString() const; // Debugowanie - tekstowa reprezentacja mapy

    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
    
    // Metoda do sprawdzania typu kafelka na danej pozycji
    Tile GetTile(float x, float y) const;
};
