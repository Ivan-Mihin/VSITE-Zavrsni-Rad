#pragma once
#include "main_menu.h"
#include "state.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class StateMainMenu : public State
{
private:
    MainMenu main_menu;

public:
    StateMainMenu();

    void handleInput(const sf::Event& event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow& window) override;
};