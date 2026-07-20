#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

enum class ExitGameItem
{
	Yes,
	No
};

class ExitGame
{
private:
	// Constants
	const float ANIMATION_SPEED = 150.f;
	const float TEXT_DEFAULT_SIZE = 50.f;
	const float TEXT_MAX_SIZE = 65.f;

	// User Interface
	sf::Sprite sprite_background;
	sf::Text text_exit;
	sf::Text text_game;
	sf::Text text_yes;
	sf::Text text_no;

	// Menu State
	ExitGameItem selected = ExitGameItem::Yes;

	// Text Animation
	float text_yes_current_size;
	float text_yes_target_size;
	float text_no_current_size;
	float text_no_target_size;

	// User Interface
	void centerText(sf::Text& text);
	void textUpdate(sf::Text& text, std::string string, float character_size, float position_x, float position_y);
	void textUpdate(sf::Text& text, float character_size, float position_x, float position_y);

public:
	ExitGame();

	// Menu State
	ExitGameItem getSelectedItem() const;

	// Game Loop
	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};