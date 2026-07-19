#pragma once
#include "board.h"
#include "tetromino.h"
#include <SFML/Graphics.hpp>

class Tetris
{
private:
	const int TEXTURE_SIZE = 30;
	const int SPRITE_BOARD_OFFSET_X = 220;
	const int SPRITE_BOARD_OFFSET_Y = 25;

	sf::Sprite sprite_background;
	sf::Sprite sprite_board;
	sf::Sprite sprite_tetromino;

	std::unique_ptr<Tetromino> tetromino;
	Board board;

	sf::Clock tetromino_fall;
	float tetromino_fall_delay;

	void spawnTetromino();
	void tetrominoFall();

public:
	Tetris();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};