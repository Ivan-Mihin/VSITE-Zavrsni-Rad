#include "state_main_menu.h"

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
            // game end
        }
    }
}

void StateMainMenu::update(float delta_time)
{
    // add pulsing text effect
}

void StateMainMenu::render(sf::RenderWindow& window)
{
    window.draw(background_sprite);
    window.draw(logo_sprite);
}