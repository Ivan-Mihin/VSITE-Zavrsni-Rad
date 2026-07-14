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

    textInitialize(text1, "Start", 50, 400.f, 550.f);
    textInitialize(text2, "Exit", 50, 400.f, 630.f);
}

void MainMenu::textInitialize(sf::Text& text, std::string string, int char_size, float pos_x, float pos_y)
{
    text.setString(string);
    text.setCharacterSize(char_size);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
    bounds.position.x + bounds.size.x / 2.f,
    bounds.position.y + bounds.size.y / 2.f
        });
    text.setPosition({ pos_x, pos_y });
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