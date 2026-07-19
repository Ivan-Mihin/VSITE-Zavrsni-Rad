#include "board.h"

Board::Board()
{
    cells.assign(ROWS, std::vector<int>(COLUMNS, 0));
}

int Board::getCell(int row, int column) const
{
    return cells[row][column];
}

int Board::getRows() const
{
    return ROWS;
}

int Board::getColumns() const
{
    return COLUMNS;
}

bool Board::isValidPosition(const std::vector<sf::Vector2i>& tetromino) const
{
    for (int i = 0; i < tetromino.size(); ++i)
    {
        // Checks left and right borders
        if (tetromino[i].x < 0 || tetromino[i].x >= COLUMNS) return false;

        // Checks bottom border
        if (tetromino[i].y >= ROWS) return false;

        // Checks collision with another tetromino
        if (cells[tetromino[i].y][tetromino[i].x] != 0) return false;
    }

    return true;
}

void Board::lockTetromino(const std::vector<sf::Vector2i>& tetromino, int color)
{
    for (int i = 0; i < tetromino.size(); ++i)
    {
        cells[tetromino[i].y][tetromino[i].x] = color;
    }
}