#pragma once
#include "tetromino.h"
#include <SFML/Graphics.hpp>

class Tetris
{
private:
	const int TEXTURE_SIZE = 30;
	const int BOARD_ROWS = 25;
	const int BOARD_COLUMNS = 12;
	const int BOARD_OFFSET_X = 220;
	const int BOARD_OFFSET_Y = 25;

	sf::Sprite sprite_background;
	sf::Sprite sprite_board;
	sf::Sprite sprite_tetromino;

	std::unique_ptr<Tetromino> tetromino;

	std::vector<std::vector<int>> board;

	void spawnTetromino();

public:
	Tetris();


	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};