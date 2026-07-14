#include "assets.h"
#include "main_menu.h"

MainMenu::MainMenu() :
    background(Assets::getInstance().getTexture("background_main_menu")),
    logo(Assets::getInstance().getTexture("logo_tetris")),
    text1(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text2(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    background.setPosition({ 0, 0 });

    logo.setOrigin({ 250, 0 });
    logo.setPosition({ 400, 50 });

    text1.setString("Start");
    text1.setCharacterSize(50);
    sf::FloatRect bounds1 = text1.getLocalBounds();
    text1.setOrigin({
    bounds1.position.x + bounds1.size.x / 2.f,
    bounds1.position.y + bounds1.size.y / 2.f
        });
    text1.setPosition({ 400.f, 540.f });

    text2.setString("Exit");
    text2.setCharacterSize(40);
    sf::FloatRect bounds2 = text2.getLocalBounds();
    text2.setOrigin({
    bounds2.position.x + bounds2.size.x / 2.f,
    bounds2.position.y + bounds2.size.y / 2.f
        });
    text2.setPosition({ 400.f, 660.f });
}

void MainMenu::handleInput(const sf::Event& event)
{   
}

void MainMenu::update(float delta_time)
{
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(logo);
    window.draw(text1);
    window.draw(text2);
}