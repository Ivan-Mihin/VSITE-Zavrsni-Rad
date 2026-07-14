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
	sf::Text text1, text2;
	MenuItem selected;

public:
	MainMenu();

	MenuItem getSelectedMenuItem() const;

	void textInitialize(sf::Text& text, std::string string, int char_size, float pos_x, float pos_y);
	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};