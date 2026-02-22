#include "state_main_menu.h"
#include "command_exit.h"
#include "game.h"

StateMainMenu::StateMainMenu()
{
    if (!background.loadFromFile("Assets/Sprites/background_main_menu.png"))
    {
        throw std::runtime_error("Failed to load background_main_menu.png");
    }
    background_sprite.emplace(background);
    background_sprite->setPosition({ 0, 0 });

    if (!logo.loadFromFile("Assets/Sprites/logo_tetris.png"))
    {
        throw std::runtime_error("Failed to load logo_tetris.png");
    }
    logo_sprite.emplace(logo);
    logo_sprite->setOrigin({ 250, 0 });
    logo_sprite->setPosition({ 400, 100 });
}

void StateMainMenu::handleInput(const sf::Event& event)
{
    if (const auto* key_event = event.getIf<sf::Event::KeyPressed>())
    {
        if (key_event->scancode == sf::Keyboard::Scancode::Enter)
        {
            // game start
        }
        else if (key_event->scancode == sf::Keyboard::Scancode::Escape)
        {
            CommandExit exit(Game::getInstance().getWindow());
            exit.execute();
        }
    }
}

void StateMainMenu::update(float delta_time)
{
    // add pulsing text effect
}

void StateMainMenu::render(sf::RenderWindow& window)
{
    window.draw(*background_sprite);
    window.draw(*logo_sprite);
}