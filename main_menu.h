#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class MainMenuItem
{
	Start,
	Exit
};

class MainMenu
{
private:
	sf::Sprite sprite_background, sprite_logo;
	sf::Text text_start, text_exit;

	MainMenuItem selected;

	const float default_size = 50.f;
	const float max_size = 65.f;

	float current_text_start_size, current_text_exit_size;
	float target_text_start_size, target_text_exit_size;

	void centerText(sf::Text& text);
	void textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y);
	void textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y);

public:
	MainMenu();

	MainMenuItem getSelectedItem() const;

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};