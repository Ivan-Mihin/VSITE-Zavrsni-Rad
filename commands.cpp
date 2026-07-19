#include "commands.h"
#include "tetris.h"
#include <SFML/Graphics.hpp>

CommandMove::CommandMove(Tetris& tetris, const sf::Vector2i& direction) :
    tetris(tetris)
{
    this->direction = direction;
}

void CommandMove::execute()
{
    tetris.moveTetromino(direction);
}