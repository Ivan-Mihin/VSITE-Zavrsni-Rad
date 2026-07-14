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

    textInitialize(text1, "EXIT", 125, 400.f, 150.f);
    textInitialize(text2, "GAME?", 125, 400.f, 270.f);
    textInitialize(text3, "Yes", 50, 400.f, 550.f);
    textInitialize(text4, "No", 50, 400.f, 630.f);
}

void ExitGame::textInitialize(sf::Text& text, std::string string, int char_size, float pos_x, float pos_y) 
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