#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StateMainMenu : public State
{
private:
    sf::Sprite background;
    sf::Sprite logo;

public:
    StateMainMenu();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};