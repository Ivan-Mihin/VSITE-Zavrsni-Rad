#include "game.h"
#include "state_main_menu.h"

Game::Game()
    : window(sf::VideoMode({ 800, 800 }), "Tetris!", sf::Style::Titlebar | sf::Style::Close)
{
    changeState(std::make_unique<StateMainMenu>());
}

Game& Game::getInstance()
{
    static Game instance;
    return instance;
}

State* Game::getCurrentState()
{
    if (states.empty())
    {
        return nullptr;
    }

    return states.top().get();
}

sf::RenderWindow& Game::getWindow()
{
    return window;
}

void Game::changeState(std::unique_ptr<State> new_state)
{
    if (!states.empty())
    {
        states.pop();
    }

    states.push(std::move(new_state));
}

void Game::popState()
{
    if (!states.empty())
    {
        states.pop();
    }
}

void Game::pushState(std::unique_ptr<State> new_state)
{
    states.push(std::move(new_state));
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

            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
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