#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino 
{
protected:
    sf::Color color;
    std::vector<std::vector<sf::Vector2i>> rotation_states;
    int current_rotation;

public:
    virtual ~Tetromino() {}

    const std::vector<std::vector<sf::Vector2i>>& getShapeMatrix() const;
    sf::Color getColor() const;

    void rotate();
};