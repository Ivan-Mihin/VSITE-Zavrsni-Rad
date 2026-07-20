#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Board
{
private:
    const int ROWS = 25;
    const int COLUMNS = 12;

    std::vector<std::vector<int>> grid;

public:
    Board();

    bool isValidPosition(const std::vector<sf::Vector2i>& tetromino) const;
    void lockTetromino(const std::vector<sf::Vector2i>& tetromino, int color);
    void clearFullLines();
    void draw(sf::RenderWindow& window, sf::Sprite& sprite_tetromino, int texture_size, float offset_x, float offset_y);
};