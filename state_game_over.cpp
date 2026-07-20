#include "state_game_over.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

void StateGameOver::handleInput(const sf::Event& event)
{
    if (const auto* key_event = event.getIf<sf::Event::KeyPressed>())
    {
        if (key_event->scancode == sf::Keyboard::Scancode::Enter)
        {
            // game restart
        }
        else if (key_event->scancode == sf::Keyboard::Scancode::Escape)
        {
            // game end
        }
    }
}

void StateGameOver::update(float delta_time)
{
}

void StateGameOver::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(logo);
}