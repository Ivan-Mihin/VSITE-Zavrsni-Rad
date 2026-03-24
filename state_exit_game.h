#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StateExitGame : public State
{
private:
    sf::Texture background;
    std::optional<sf::Sprite> background_sprite;
    sf::Font font;
    std::optional<sf::Text> text1, text2;

public:
    StateExitGame();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};