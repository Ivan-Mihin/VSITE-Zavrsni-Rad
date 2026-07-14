#include "assets.h"
#include "exit_game.h"

ExitGame::ExitGame() :
    background(Assets::getInstance().getTexture("background_main_menu")),
    text1(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text2(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text3(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text4(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    background.setPosition({ 0, 0 });

    text1.setString("EXIT");
    text1.setCharacterSize(125);
    sf::FloatRect bounds1 = text1.getLocalBounds();
    text1.setOrigin({
    bounds1.position.x + bounds1.size.x / 2.f,
    bounds1.position.y + bounds1.size.y / 2.f
        });
    text1.setPosition({ 400.f, 150.f });

    text2.setString("GAME?");
    text2.setCharacterSize(125);
    sf::FloatRect bounds2 = text2.getLocalBounds();
    text2.setOrigin({
    bounds2.position.x + bounds2.size.x / 2.f,
    bounds2.position.y + bounds2.size.y / 2.f
        });
    text2.setPosition({ 400.f, 270.f });

    text3.setString("Yes");
    text3.setCharacterSize(50);
    sf::FloatRect bounds3 = text3.getLocalBounds();
    text3.setOrigin({
    bounds3.position.x + bounds3.size.x / 2.f,
    bounds3.position.y + bounds3.size.y / 2.f
        });
    text3.setPosition({ 400.f, 550.f });

    text4.setString("No");
    text4.setCharacterSize(50);
    sf::FloatRect bounds4 = text4.getLocalBounds();
    text4.setOrigin({
    bounds4.position.x + bounds4.size.x / 2.f,
    bounds4.position.y + bounds4.size.y / 2.f
        });
    text4.setPosition({ 400.f, 630.f });
}

void ExitGame::handleInput(const sf::Event& event)
{
}

void ExitGame::update(float delta_time)
{
}

void ExitGame::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
}