#include "tetromino.h"

const std::vector<std::vector<sf::Vector2i>>& Tetromino::getShapeMatrix() const
{
	return rotation_states;
}

sf::Color Tetromino::getColor() const 
{ 
	return color; 
}

void Tetromino::rotate() 
{
	current_rotation = (current_rotation + 1) % rotation_states.size();
}