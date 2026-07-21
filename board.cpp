#include "audio.h"
#include "board.h"
#include "subject.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>

Board::Board()
{
    grid.assign(ROWS, std::vector<int>(COLUMNS, 0));
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

    Audio::getInstance().playSound("floor");

}

void Board::clearFullLines()
{
    int cleared_lines_count = 0;

    for (int row = ROWS - 1; row >= 0; --row)
    {
        bool is_line_full = true;

        for (int column = 0; column < COLUMNS; ++column)
        {
            if (grid[row][column] == 0)
            {
                is_line_full = false;
                break;
            }
        }

        if (is_line_full)
        {
            // Deletes the full line, adds a new one on top, and resets to the same row to recheck it after the shift
            Audio::getInstance().playSound("clear_line");
            grid.erase(grid.begin() + row);
            grid.insert(grid.begin(), std::vector<int>(COLUMNS, 0));
            ++row;
            ++cleared_lines_count;
        }
    }

    switch (cleared_lines_count)
    {
        case 0:
            notifyObservers(GameEvent::NoLinesCleared);
            break;
        case 1:
            notifyObservers(GameEvent::LinesCleared_1);
            break;
        case 2:
            notifyObservers(GameEvent::LinesCleared_2);
            break;
        case 3:
            notifyObservers(GameEvent::LinesCleared_3);
            break;
        case 4:
            notifyObservers(GameEvent::LinesCleared_4);
            break;
    }
}

bool Board::isGameOver() const
{
    for (int row = 0; row <= game_over_row; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
            if (grid[row][column] != 0)
            {
                return true;
            }
        }
    }

    return false;
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

                // Calculates which part of the texture is taken for drawing
                sf::Vector2i position = { color * texture_size, 0 };
                sf::Vector2i size = { texture_size, texture_size };
                sprite_tetromino.setTextureRect(sf::IntRect(position, size));

                float position_x = static_cast<float>(column * texture_size + offset_x);
                float position_y = static_cast<float>(row * texture_size + offset_y);
                sprite_tetromino.setPosition({ position_x, position_y });

                window.draw(sprite_tetromino);
            }
        }
    }
}