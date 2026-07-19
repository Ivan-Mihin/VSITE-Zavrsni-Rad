#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Board
{
private:
    const int ROWS = 25;
    const int COLUMNS = 12;

    std::vector<std::vector<int>> cells;

public:
    Board();

    int getCell(int row, int column) const;
    int getRows() const;
    int getColumns() const;

    bool isValidPosition(const std::vector<sf::Vector2i>& tetromino) const;
    void lockTetromino(const std::vector<sf::Vector2i>& tetromino, int color);
};