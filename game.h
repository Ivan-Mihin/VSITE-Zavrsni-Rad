#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "state.h"

class Game
{
private:
    Game();

    static Game* instance;
    std::stack<State*> states;
    sf::RenderWindow window;

public:
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static void destroy();
    static Game& getInstance();

    State* getCurrentState();
    sf::Window& getWindow();

    void changeState(State* new_state);
    void popState();
    void pushState(State* new_state);
    void run();
};