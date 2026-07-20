#pragma once

#include "exit_game.h"
#include "state.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class StateExitGame : public State
{
private:
    ExitGame exit_game;

public:
    StateExitGame();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};