#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>

class StatePlaying : public State
{
private:
    sf::Sprite background;

public:
    StatePlaying();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};