#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StateMainMenu : public State
{
private:
    sf::Texture background;
    std::optional<sf::Sprite> background_sprite;
    sf::Texture logo;
    std::optional<sf::Sprite> logo_sprite;

public:
    StateMainMenu();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};