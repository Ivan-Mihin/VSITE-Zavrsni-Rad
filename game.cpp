#include "game.h"
#include "state_main_menu.h"

Game::Game()
    : window(sf::VideoMode({ 800, 800 }), "Tetris!", sf::Style::Titlebar | sf::Style::Close)
{
    // change to a new state
}

Game::~Game()
{
    while (!states.empty())
    {
        delete states.top();
        states.pop();
    }
}

Game* Game::instance = nullptr;

void Game::destroy()
{
    delete instance;
    instance = nullptr;
}

Game& Game::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }

    return *instance;
}

State* Game::getCurrentState()
{
    if (states.empty())
    {
        return nullptr;
    }

    return states.top();
}

sf::Window& Game::getWindow()
{
    return window;
}

void Game::changeState(State* new_state)
{
    if (!states.empty())
    {
        delete states.top();
        states.pop();
    }

    states.push(new_state);
}

void Game::popState()
{
    if (!states.empty())
    {
        delete states.top();
        states.pop();
    }
}

void Game::pushState(State* new_state)
{
    states.push(new_state);
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float delta_time = clock.restart().asSeconds();

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (auto current = getCurrentState())
            {
                current->handleInput(*event);
            }
        }

        if (auto current = getCurrentState())
        {
            current->update(delta_time);

            window.clear(sf::Color::Black);
            current->render(window);
            window.display();
        }
    }
}