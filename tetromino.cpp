#include "tetromino.h"

const std::vector<std::vector<sf::Vector2i>>& Tetromino::getRotationStates() const
{
	return rotation_states;
}

TetrominoShape Tetromino::getShape() const
{
	return shape;
}

TetrominoColor Tetromino::getColor() const
{ 
	return color; 
}

sf::Vector2i Tetromino::getPosition() const
{
	return position;
}

void Tetromino::setPosition(const sf::Vector2i& position)
{
	this->position = position;
}

void Tetromino::rotate() 
{
	current_rotation = (current_rotation + 1) % rotation_states.size();
}