#pragma once

#include "state.h"
#include "tetris.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class StatePlaying : public State
{
private:
    Tetris tetris;

public:
    StatePlaying();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};