#include "assets.h"
#include "game.h"
#include "state_exit_game.h"

StateExitGame::StateExitGame() :
    background(Assets::getInstance().getTexture("background_main_menu_paused")),
    text1(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text2(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{

    background.setPosition({ 0, 0 });

    text1.setPosition({ 200, 100 });
    text1.setString("Are you sure");

    text2.setPosition({ 400, 100 });
    text2.setString("Y/N");
}

void StateExitGame::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
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
}

void StateExitGame::update(float delta_time)
{
    // change later
}

void StateExitGame::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(text1);
    window.draw(text2);
}