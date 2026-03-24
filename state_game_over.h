#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StateGameOver : public State
{
private:
    sf::Texture background;
    sf::Sprite background_sprite;
    sf::Texture logo;
    sf::Sprite logo_sprite;

public:
    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};