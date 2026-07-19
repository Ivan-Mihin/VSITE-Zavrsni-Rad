#pragma once
#include <map>
#include <memory>
#include "board.h"
#include "commands.h"
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

	std::map<sf::Keyboard::Scancode, std::unique_ptr<ICommand>> key_bindings;

	sf::Clock tetromino_fall;
	float tetromino_fall_delay;

	bool is_soft_dropping = false;
	float speed_default = 1.0f;
	float speed_soft_drop = 0.05f;

	void spawnTetromino();

public:
	Tetris();

	void moveTetromino(const sf::Vector2i& offset);
	void rotateTetromino();
	void hardDropTetromino();

	void setSoftDrop(bool active);

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};