#include "assets.h"
#include "game.h"
#include "state_exit_game.h"
#include "state_main_menu.h"

StateMainMenu::StateMainMenu() :
    background(Assets::getInstance().getTexture("background_main_menu")),
    logo(Assets::getInstance().getTexture("logo_tetris"))
{
    background.setPosition({ 0, 0 });

    logo.setOrigin({ 250, 0 });
    logo.setPosition({ 400, 100 });
}

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
            // switch to StatePlaying
        }
    }
}

void StateMainMenu::update(float delta_time)
{
    // add pulsing text effect
}

void StateMainMenu::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(logo);
}