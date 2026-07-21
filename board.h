#pragma once

#include "subject.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>

class Board : public Subject
{
private:
    // Constants
    const int ROWS = 25;
    const int COLUMNS = 12;

    // Core Components
    std::vector<std::vector<int>> grid;

    // Game State Queries
    int game_over_row = 3;

public:
    Board();

    // Getters
    int getRows() const;
    int getColumns() const;

    // Grid Management
    bool isValidPosition(const std::vector<sf::Vector2i>& tetromino) const;
    void lockTetromino(const std::vector<sf::Vector2i>& tetromino, int color);
    void clearFullLines();

    // Game State Queries
    bool isGameOver() const;

    // Rendering
    void draw(sf::RenderWindow& window, sf::Sprite& sprite_tetromino, int texture_size, float offset_x, float offset_y);
};