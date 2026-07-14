#pragma once
#include <SFML/Graphics.hpp>

class ExitGame
{
private:
	sf::Sprite background;
	sf::Text text1, text2, text3, text4;

public:
	ExitGame();

	void handleInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};