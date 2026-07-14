#include "game.h"
#include "state_exit_game.h"

StateExitGame::StateExitGame() {}

void StateExitGame::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Space ||
            key->scancode == sf::Keyboard::Scancode::Enter)
        {
            if (exit_game.getSelectedItem() == ExitGameItem::Yes)
            {
                Game::getInstance().getWindow().close();
            }
            else if (exit_game.getSelectedItem() == ExitGameItem::No)
            {
                Game::getInstance().popState();
            }
        }

        if (key->scancode == sf::Keyboard::Scancode::Y ||
            key->scancode == sf::Keyboard::Scancode::Z)
        {
            Game::getInstance().getWindow().close();
        }

        if (key->scancode == sf::Keyboard::Scancode::N ||
            key->scancode == sf::Keyboard::Scancode::Escape)
        {
            Game::getInstance().popState();
        }
    }

    exit_game.handleInput(event);
}

void StateExitGame::update(float delta_time)
{
    exit_game.update(delta_time);
}

void StateExitGame::render(sf::RenderWindow& window)
{
    exit_game.render(window);
}