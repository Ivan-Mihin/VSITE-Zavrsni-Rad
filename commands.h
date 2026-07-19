#pragma once
#include "ICommand.h"
#include <SFML/Graphics.hpp>

class Tetris;

class CommandMove : public ICommand
{
private:
    Tetris& tetris;
    sf::Vector2i direction;

public:
    CommandMove(class Tetris& tetris, const sf::Vector2i& direction);
    void execute() override;
};

class CommandRotate : public ICommand
{
private:
    Tetris& tetris;

public:
    CommandRotate(Tetris& tetris);
    void execute() override;
};

class CommandHardDrop : public ICommand
{
private:
    Tetris& tetris;

public:
    CommandHardDrop(Tetris& tetris);
    void execute() override;
};