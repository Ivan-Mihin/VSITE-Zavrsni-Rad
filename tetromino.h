#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino 
{
protected:
    std::vector<sf::Vector2i> shape_matrix;
    sf::Color color;
    int rotation;

public:
    virtual ~Tetromino() {}

    const std::vector<sf::Vector2i>& getShapeMatrix() const;
    sf::Color getColor() const;

    void rotate();
};