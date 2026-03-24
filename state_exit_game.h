#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StateExitGame : public State
{
private:
    sf::Sprite background;
    sf::Text text1, text2;

public:
    StateExitGame();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};