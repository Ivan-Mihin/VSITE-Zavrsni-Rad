#include "game.h"
#include "state_exit_game.h"
#include "state_game_over.h"
#include "state_playing.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <memory>

StatePlaying::StatePlaying() {}

void StatePlaying::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Escape)
        {
            Game::getInstance().pushState(std::make_unique<StateExitGame>());
        }
    }

    tetris.handleInput(event);
}

void StatePlaying::update(float delta_time)
{
    tetris.update(delta_time);

    if (tetris.isGameOver())
    {
        Game::getInstance().changeState(std::make_unique<StateGameOver>());
    }
}

void StatePlaying::render(sf::RenderWindow& window)
{
    tetris.render(window);
}