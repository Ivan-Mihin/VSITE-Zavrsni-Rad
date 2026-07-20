#pragma once
#include <map>
#include <memory>
#include "board.h"
#include "commands.h"
#include "tetromino.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Tetris
{
private:
	const int TEXTURE_SIZE = 30;
	const float SPRITE_BOARD_OFFSET_X = 220.f;
	const float SPRITE_BOARD_OFFSET_Y = 25.f;

	sf::Sprite sprite_background;
	sf::Sprite sprite_board;
	sf::Sprite sprite_tetromino;
	sf::Sprite sprite_tetromino_ghost;
	sf::Sprite sprite_game_over_line;

	Board board;
	std::unique_ptr<Tetromino> tetromino;
	std::map<sf::Keyboard::Scancode, std::unique_ptr<ICommand>> key_bindings;

	sf::Clock tetromino_fall;
	float tetromino_fall_delay = 0.5f;

	bool is_soft_dropping = false;
	float speed_default = 1.0f;
	float speed_soft_drop = 0.05f;

	void spawnTetromino();
	void setSoftDrop(bool active);

	void drawGhostTetromino(sf::RenderWindow& window);
	void drawActiveTetromino(sf::RenderWindow& window);

public:
	Tetris();

	bool isGameOver() const;

	void moveTetromino(const sf::Vector2i& offset);
	void rotateTetromino();
	void hardDropTetromino();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};