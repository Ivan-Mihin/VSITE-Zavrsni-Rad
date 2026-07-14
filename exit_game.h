#pragma once
#include <SFML/Graphics.hpp>

enum class ExitGameItem
{
	Yes,
	No
};

class ExitGame
{
private:
	sf::Sprite sprite_background;
	sf::Text text_exit, text_game, text_yes, text_no;

	ExitGameItem selected;

	const float default_size = 50.f;
	const float max_size = 65.f;

	float current_text_yes_size, current_text_no_size;
	float target_text_yes_size, target_text_no_size;

	void centerText(sf::Text& text);
	void textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y);
	void textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y);

public:
	ExitGame();

	ExitGameItem getSelectedItem() const;

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};