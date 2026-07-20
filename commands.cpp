#include "commands.h"
#include "tetris.h"
#include <SFML/System.hpp>

CommandMove::CommandMove(Tetris& tetris, const sf::Vector2i& direction) :
    tetris(tetris)
{
    this->direction = direction;
}

void CommandMove::execute()
{
    tetris.moveTetromino(direction);
}

CommandRotate::CommandRotate(Tetris& tetris)
    : tetris(tetris)
{
}

void CommandRotate::execute()
{
    tetris.rotateTetromino();
}

CommandHardDrop::CommandHardDrop(Tetris& tetris)
    : tetris(tetris)
{
}

void CommandHardDrop::execute()
{
    tetris.hardDropTetromino();
}