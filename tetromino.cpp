#include "tetromino.h"

const std::vector<sf::Vector2i>& Tetromino::getShapeMatrix() const 
{
	return shape_matrix;
}

sf::Color Tetromino::getColor() const 
{ 
	return color; 
}

void Tetromino::rotate() 
{
	// add later
}