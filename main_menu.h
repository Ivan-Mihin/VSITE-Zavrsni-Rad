#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
	sf::Sprite background;
	sf::Sprite logo;
	sf::Text text1, text2;

public:
	MainMenu();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};