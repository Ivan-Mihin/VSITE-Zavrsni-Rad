#pragma once

#include "state.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <stack>

class Game
{
private:
    Game();

    std::stack<std::unique_ptr<State>> states;
    sf::RenderWindow window;

public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& getInstance();

    State* getCurrentState();
    sf::RenderWindow& getWindow();

    void changeState(std::unique_ptr<State> new_state);
    void popState();
    void pushState(std::unique_ptr<State> new_state);
    void run();
};