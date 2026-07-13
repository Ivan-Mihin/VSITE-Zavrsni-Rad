#pragma once
#include "tetromino.h"
#include <SFML/Graphics.hpp>

class Tetris
{
private:
	std::unique_ptr<Tetromino> tetromino;

public:
	Tetris();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};