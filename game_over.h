#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

enum class GameOverItem
{
	Restart,
	Exit
};

class GameOver
{
private:
	// Constants
	const float ANIMATION_SPEED = 150.f;
	const float TEXT_DEFAULT_SIZE = 50.f;
	const float TEXT_MAX_SIZE = 65.f;

	// User Interface
	sf::Sprite sprite_background;
	sf::Sprite sprite_logo_game_over_1;
	sf::Sprite sprite_logo_game_over_2;
	sf::Text text_restart;
	sf::Text text_exit;
	sf::Text key_bindings;

	// Menu State
	GameOverItem selected = GameOverItem::Restart;;

	// Text Animation
	float text_start_current_size;
	float text_start_target_size;
	float text_exit_current_size;
	float text_exit_target_size;

	// User Interface
	void centerText(sf::Text& text);
	void textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y);
	void textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y);

public:
	GameOver();

	// Menu State
	GameOverItem getSelectedItem() const;

	// Game Loop
	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};