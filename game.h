#pragma once
#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include "state.h"

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
    sf::Window& getWindow();

    void changeState(std::unique_ptr<State> new_state);
    void popState();
    void pushState(std::unique_ptr<State> new_state);
    void run();
};