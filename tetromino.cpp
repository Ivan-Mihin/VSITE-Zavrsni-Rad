#include "tetromino.h"

#include <SFML/System.hpp>

#include <vector>

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

std::vector<sf::Vector2i> Tetromino::getBlocks() const
{
	std::vector<sf::Vector2i> blocks;

	for (int i = 0; i < 4; ++i)
	{
		blocks.push_back(position + rotation_states[current_rotation][i]);
	}

	return blocks;
}

const std::vector<std::vector<sf::Vector2i>>& Tetromino::getRotationStates() const
{
	return rotation_states;
}

void Tetromino::setPosition(const sf::Vector2i& position)
{
	this->position = position;
}

void Tetromino::move(const sf::Vector2i& offset)
{
	position += offset;
}

void Tetromino::rotate() 
{
	current_rotation = (current_rotation + 1) % rotation_states.size();
}