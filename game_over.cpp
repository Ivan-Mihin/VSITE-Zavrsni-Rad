#include "audio.h"
#include "assets.h"
#include "game_over.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

GameOver::GameOver() :
    sprite_background(Assets::getInstance().getTexture("background")),
    sprite_logo_game_over_1(Assets::getInstance().getTexture("logo_game_over_1")),
    sprite_logo_game_over_2(Assets::getInstance().getTexture("logo_game_over_2")),
    text_restart(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_exit(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    key_bindings(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    sprite_background.setPosition({ 0, 0 });

    sprite_logo_game_over_1.setOrigin({ 150, 0 });
    sprite_logo_game_over_1.setPosition({ 200, 50 });

    sprite_logo_game_over_2.setOrigin({ 208, 0 });
    sprite_logo_game_over_2.setPosition({ 550, 100 });

    textUpdate(text_restart, "Restart", 50, 400.f, 550.f);
    textUpdate(text_exit, "Exit", 50, 400.f, 630.f);
    textUpdate(key_bindings, "Select <Space> <Enter> - Cancel <Escape>", 20, 400.f, 770.f);

    text_start_current_size = TEXT_MAX_SIZE;
    text_start_target_size = TEXT_MAX_SIZE;
    text_exit_current_size = TEXT_DEFAULT_SIZE;
    text_exit_target_size = TEXT_DEFAULT_SIZE;
}

void GameOver::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
}

void GameOver::textUpdate(sf::Text& text, std::string string, float character_size, float position_x, float position_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

void GameOver::textUpdate(sf::Text& text, float character_size, float position_x, float position_y)
{
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

GameOverItem GameOver::getSelectedItem() const
{
    return selected;
}

void GameOver::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>())
    {
        if (key->scancode == sf::Keyboard::Scancode::Up)
        {
            if (selected != GameOverItem::Restart)
            {
                Audio::getInstance().playSound("navigation");
            }

            selected = GameOverItem::Restart;

            text_start_target_size = TEXT_MAX_SIZE;
            text_exit_target_size = TEXT_DEFAULT_SIZE;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            if (selected != GameOverItem::Exit)
            {
                Audio::getInstance().playSound("navigation");
            }

            selected = GameOverItem::Exit;

            text_start_target_size = TEXT_DEFAULT_SIZE;
            text_exit_target_size = TEXT_MAX_SIZE;
        }
    }
}

void GameOver::update(float delta_time)
{
    // Increase text size until it reaches max size
    if (text_start_current_size < text_start_target_size)
    {
        text_start_current_size += ANIMATION_SPEED * delta_time;

        if (text_start_current_size > text_start_target_size) text_start_current_size = TEXT_MAX_SIZE;
    }

    if (text_exit_current_size < text_exit_target_size)
    {
        text_exit_current_size += ANIMATION_SPEED * delta_time;

        if (text_exit_current_size > text_exit_target_size) text_exit_current_size = TEXT_MAX_SIZE;
    }

    // Decrease text size until it reaches default size
    if (text_start_current_size > text_start_target_size)
    {
        text_start_current_size -= ANIMATION_SPEED * delta_time;

        if (text_start_current_size < text_start_target_size) text_start_current_size = TEXT_DEFAULT_SIZE;
    }

    if (text_exit_current_size > text_exit_target_size)
    {
        text_exit_current_size -= ANIMATION_SPEED * delta_time;

        if (text_exit_current_size < text_exit_target_size) text_exit_current_size = TEXT_DEFAULT_SIZE;
    }

    textUpdate(text_restart, text_start_current_size, 400.f, 550.f);
    textUpdate(text_exit, text_exit_current_size, 400.f, 630.f);
}

void GameOver::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_logo_game_over_1);
    window.draw(sprite_logo_game_over_2);
    window.draw(text_restart);
    window.draw(text_exit);
    window.draw(key_bindings);
}