#pragma once

#include "game_over.h"
#include "state.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class StateGameOver : public State
{
private:
    GameOver game_over;

public:
    StateGameOver();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};