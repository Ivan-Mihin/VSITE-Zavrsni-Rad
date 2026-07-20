#include "game.h"
#include "state_game_over.h"
#include "state_exit_game.h"
#include "state_playing.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <memory>

StateGameOver::StateGameOver() {}

void StateGameOver::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Space ||
            key->scancode == sf::Keyboard::Scancode::Enter)
        {
            if (game_over.getSelectedItem() == GameOverItem::Restart)
            {
                Game::getInstance().changeState(std::make_unique<StatePlaying>());
            }
            else if (game_over.getSelectedItem() == GameOverItem::Exit)
            {
                Game::getInstance().pushState(std::make_unique<StateExitGame>());
            }
        }

        if (key->scancode == sf::Keyboard::Scancode::Escape)
        {
            Game::getInstance().pushState(std::make_unique<StateExitGame>());
        }
    }

    game_over.handleInput(event);
}

void StateGameOver::update(float delta_time)
{
    game_over.update(delta_time);
}

void StateGameOver::render(sf::RenderWindow& window)
{
    game_over.render(window);
}