#pragma once
#include "tetromino.h"
#include <SFML/Graphics.hpp>

class Tetris
{
private:
	sf::Sprite tetrominoSprite;
	std::unique_ptr<Tetromino> tetromino;

public:
	Tetris();

	void handleInput(const sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};