#pragma once
#include "tetromino_enums.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Tetromino 
{
protected:
    TetrominoShape shape;
    TetrominoColor color;
    std::vector<std::vector<sf::Vector2i>> rotation_states;
    int current_rotation;

public:
    virtual ~Tetromino() {}

    TetrominoShape getShape() const;
    TetrominoColor getColor() const;
    const std::vector<std::vector<sf::Vector2i>>& getRotationStates() const;
    void rotate();
};