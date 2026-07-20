#include "board.h"
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

Board::Board()
{
    grid.assign(ROWS, std::vector<int>(COLUMNS, 0));
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
        if (grid[tetromino[i].y][tetromino[i].x] != 0) return false;
    }

    return true;
}

void Board::lockTetromino(const std::vector<sf::Vector2i>& tetromino, int color)
{
    for (int i = 0; i < tetromino.size(); ++i)
    {
        grid[tetromino[i].y][tetromino[i].x] = color;
    }
}

void Board::draw(sf::RenderWindow& window, sf::Sprite& sprite_tetromino, int texture_size, float offset_x, float offset_y)
{
    for (int row = 0; row < ROWS; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
            if (grid[row][column] > 0)
            {
                int color = grid[row][column] - 1;

                sf::Vector2i position = { color * texture_size, 0 };
                sf::Vector2i size = { texture_size, texture_size };
                sprite_tetromino.setTextureRect(sf::IntRect(position, size));

                float pos_x = static_cast<float>(column * texture_size + offset_x);
                float pos_y = static_cast<float>(row * texture_size + offset_y);

                sprite_tetromino.setPosition({ pos_x, pos_y });
                window.draw(sprite_tetromino);
            }
        }
    }
}