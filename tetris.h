#pragma once

#include "board.h"
#include "commands.h"
#include "manager_score.h"
#include "tetromino.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <map>
#include <memory>

class Tetris
{
private:
	// Constants
	const int TEXTURE_SIZE = 30;
	const float SPRITE_BOARD_OFFSET_X = 220.f;
	const float SPRITE_BOARD_OFFSET_Y = 25.f;
	const float LOCK_DELAY_TIME = 1.0f;
	const float SPEED_DEFAULT = 1.0f;
	const float SPEED_SOFT_DROP = 0.05f;

	// Sprites
	sf::Sprite sprite_background;
	sf::Sprite sprite_board;
	sf::Sprite sprite_tetromino;
	sf::Sprite sprite_tetromino_ghost;
	sf::Sprite sprite_game_over_line;

	// Core Components
	Board board;
	std::unique_ptr<Tetromino> tetromino;
	std::map<sf::Keyboard::Scancode, std::unique_ptr<ICommand>> key_bindings;

	// Tetromino Movement
	sf::Clock clock_tetromino_drop;
	bool is_soft_dropping = false;

	// Lock Delay
	sf::Clock clock_lock_delay;
	bool is_tetromino_grounded = false;
	sf::RectangleShape lock_delay_bar_left;
	sf::RectangleShape lock_delay_bar_right;

	// Observers
	ManagerScore manager_score;

	// Tetromino Movement
	void spawnTetromino();
	void setSoftDrop(bool active);

	// Lock Delay
	bool checkTetrominoGrounded() const;
	void resetLockDelay();

	// Game Loop
	bool updateLockDelay();
	void updateTetrominoDrop();
	void drawActiveTetromino(sf::RenderWindow& window);
	void drawGhostTetromino(sf::RenderWindow& window);
	void drawLockDelayBars(sf::RenderWindow& window);

public:
	Tetris();

	// Game State Queries
	bool isGameOver();

	// Commands
	void moveTetromino(const sf::Vector2i& offset);
	void rotateTetromino();
	void hardDropTetromino();

	// Game Loop
	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};