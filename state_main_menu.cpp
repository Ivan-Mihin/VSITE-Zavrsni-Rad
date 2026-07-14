#include "game.h"
#include "state_exit_game.h"
#include "state_main_menu.h"
#include "state_playing.h"

StateMainMenu::StateMainMenu() {}

void StateMainMenu::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Escape)
        {
            Game::getInstance().pushState(std::make_unique<StateExitGame>());
        }

        if (key->scancode == sf::Keyboard::Scancode::Space)
        {
            Game::getInstance().pushState(std::make_unique<StatePlaying>());
        }
    }

    main_menu.handleInput(event);
}

void StateMainMenu::update(float delta_time)
{
    main_menu.update(delta_time);
}

void StateMainMenu::render(sf::RenderWindow& window)
{
    main_menu.render(window);
}