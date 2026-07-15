#pragma once
#include "tetromino_enums.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Tetromino 
{
protected:
    TetrominoShape shape;
    TetrominoColor color;
    sf::Vector2i position;
    std::vector<std::vector<sf::Vector2i>> rotation_states;
    int current_rotation;

public:
    virtual ~Tetromino() {}

    TetrominoShape getShape() const;
    TetrominoColor getColor() const;
    sf::Vector2i getPosition() const;

    void setPosition(const sf::Vector2i& pos);

    const std::vector<std::vector<sf::Vector2i>>& getRotationStates() const;
    void rotate();
};