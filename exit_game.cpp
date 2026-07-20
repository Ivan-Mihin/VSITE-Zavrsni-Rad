#include "assets.h"
#include "exit_game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

ExitGame::ExitGame() :
    sprite_background(Assets::getInstance().getTexture("background")),
    text_exit(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_game(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_yes(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_no(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    sprite_background.setPosition({ 0, 0 });

    textUpdate(text_exit, "EXIT", 125, 400.f, 150.f);
    textUpdate(text_game, "GAME?", 125, 400.f, 270.f);
    textUpdate(text_yes, "Yes", 50, 400.f, 550.f);
    textUpdate(text_no, "No", 50, 400.f, 630.f);

    text_yes_current_size = TEXT_MAX_SIZE;
    text_yes_target_size = TEXT_MAX_SIZE;
    text_no_current_size = TEXT_DEFAULT_SIZE;
    text_no_target_size = TEXT_DEFAULT_SIZE;
}

void ExitGame::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
}

void ExitGame::textUpdate(sf::Text& text, std::string string, float character_size, float position_x, float position_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

void ExitGame::textUpdate(sf::Text& text, float character_size, float position_x, float position_y)
{
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

ExitGameItem ExitGame::getSelectedItem() const
{
    return selected;
}

void ExitGame::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Up)
        {
            selected = ExitGameItem::Yes;

            text_yes_target_size = TEXT_MAX_SIZE;
            text_no_target_size = TEXT_DEFAULT_SIZE;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            selected = ExitGameItem::No;

            text_yes_target_size = TEXT_DEFAULT_SIZE;
            text_no_target_size = TEXT_MAX_SIZE;
        }
    }
}

void ExitGame::update(float delta_time)
{
    // Increase text size until it reaches max size
    if (text_yes_current_size < text_yes_target_size)
    {
        text_yes_current_size += ANIMATION_SPEED * delta_time;

        if (text_yes_current_size > text_yes_target_size) text_yes_current_size = TEXT_MAX_SIZE;
    }

    if (text_no_current_size < text_no_target_size)
    {
        text_no_current_size += ANIMATION_SPEED * delta_time;

        if (text_no_current_size > text_no_target_size) text_no_current_size = TEXT_MAX_SIZE;
    }

    // Decrease text size until it reaches default size
    if (text_yes_current_size > text_yes_target_size)
    {
        text_yes_current_size -= ANIMATION_SPEED * delta_time;

        if (text_yes_current_size < text_yes_target_size) text_yes_current_size = TEXT_DEFAULT_SIZE;
    }

    if (text_no_current_size > text_no_target_size)
    {
        text_no_current_size -= ANIMATION_SPEED * delta_time;

        if (text_no_current_size < text_no_target_size) text_no_current_size = TEXT_DEFAULT_SIZE;
    }

    textUpdate(text_yes, text_yes_current_size, 400.f, 550.f);
    textUpdate(text_no, text_no_current_size, 400.f, 630.f);
}

void ExitGame::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(text_exit);
    window.draw(text_game);
    window.draw(text_yes);
    window.draw(text_no);
}