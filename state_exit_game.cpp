#include "state_exit_game.h"
#include "game.h"

StateExitGame::StateExitGame()
{
    if (!background.loadFromFile("Assets/Sprites/background_main_menu_paused.png"))
    {
        throw std::runtime_error("Failed to load background_main_menu_paused.png");
    }
    background_sprite.emplace(background);
    background_sprite->setPosition({ 0, 0 });

    if (!font.openFromFile("Assets/Fonts/BaiJamjuree-Regular.ttf"))
    {
        throw std::runtime_error("Failed to load font BaiJamjuree-Regular.ttf");
    }
    text1.emplace(font);
    text1->setPosition({ 200, 100 });
    text1->setString("Are you sure");

    text2.emplace(font);
    text2->setPosition({ 400, 100 });
    text2->setString("Y/N");
}

void StateExitGame::handleInput(const sf::Event& event)
{
    if (const auto* key_event = event.getIf<sf::Event::KeyPressed>())
    {
        if (key_event->scancode == sf::Keyboard::Scancode::Enter)
        {
            // change later
        }
    }
}

void StateExitGame::update(float delta_time)
{
    // change later
}

void StateExitGame::render(sf::RenderWindow& window)
{
    window.draw(*background_sprite);
    window.draw(*text1);
    window.draw(*text2);
}