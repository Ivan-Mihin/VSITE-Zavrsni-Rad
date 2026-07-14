#pragma once
#include <SFML/Graphics.hpp>

enum class MenuItem
{
	Start,
	Exit
};

class MainMenu
{
private:
	sf::Sprite background;
	sf::Sprite logo;
	sf::Text start, exit;
	MenuItem selected;

	const float default_size = 50.f;
	const float max_size = 65.f;

	float current_start_size, current_exit_size;
	float target_start_size, target_exit_size;

	void centerText(sf::Text& text);
	void textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y);
	void textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y);

public:
	MainMenu();

	MenuItem getSelectedMenuItem() const;

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};