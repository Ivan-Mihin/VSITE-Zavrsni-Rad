#pragma once
#include "tetromino.h"
#include <SFML/Graphics.hpp>

class Tetris
{
private:
	sf::Sprite sprite_background;
	sf::Sprite sprite_board;
	std::unique_ptr<Tetromino> tetromino;

public:
	Tetris();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};