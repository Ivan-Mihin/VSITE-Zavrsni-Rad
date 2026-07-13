#include "assets.h"
#include "game.h"
#include "state_exit_game.h"
#include "state_playing.h"

StatePlaying::StatePlaying() :
    background(Assets::getInstance().getTexture("background_main_menu"))
{
    background.setPosition({ 0, 0 });
}

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
}

void StatePlaying::render(sf::RenderWindow& window)
{
    window.draw(background);
    tetris.render(window);
}