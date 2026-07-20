#include "assets.h"
#include "game_over.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

GameOver::GameOver() :
    sprite_background(Assets::getInstance().getTexture("background")),
    sprite_logo_game_over_1(Assets::getInstance().getTexture("logo_game_over_1")),
    sprite_logo_game_over_2(Assets::getInstance().getTexture("logo_game_over_2")),
    text_restart(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_exit(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    sprite_background.setPosition({ 0, 0 });

    sprite_logo_game_over_1.setOrigin({ 150, 0 });
    sprite_logo_game_over_1.setPosition({ 200, 50 });

    sprite_logo_game_over_2.setOrigin({ 208, 0 });
    sprite_logo_game_over_2.setPosition({ 550, 100 });

    textUpdate(text_restart, "Restart", 50, 400.f, 550.f);
    textUpdate(text_exit, "Exit", 50, 400.f, 630.f);

    selected = GameOverItem::Restart;

    current_text_start_size = max_size;
    current_text_exit_size = default_size;

    target_text_start_size = max_size;
    target_text_exit_size = default_size;
}

void GameOver::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
}

void GameOver::textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
}

void GameOver::textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y)
{
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
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
            selected = GameOverItem::Restart;

            target_text_start_size = max_size;
            target_text_exit_size = default_size;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            selected = GameOverItem::Exit;

            target_text_start_size = default_size;
            target_text_exit_size = max_size;
        }
    }
}

void GameOver::update(float delta_time)
{
    float animation_speed = 150.f;

    if (current_text_start_size < target_text_start_size)
    {
        current_text_start_size += animation_speed * delta_time;

        if (current_text_start_size > target_text_start_size) current_text_start_size = max_size;
    }

    if (current_text_start_size > target_text_start_size)
    {
        current_text_start_size -= animation_speed * delta_time;

        if (current_text_start_size < target_text_start_size) current_text_start_size = default_size;
    }

    if (current_text_exit_size < target_text_exit_size)
    {
        current_text_exit_size += animation_speed * delta_time;

        if (current_text_exit_size > target_text_exit_size) current_text_exit_size = max_size;
    }

    if (current_text_exit_size > target_text_exit_size)
    {
        current_text_exit_size -= animation_speed * delta_time;

        if (current_text_exit_size < target_text_exit_size) current_text_exit_size = default_size;
    }

    textUpdate(text_restart, current_text_start_size, 400.f, 550.f);
    textUpdate(text_exit, current_text_exit_size, 400.f, 630.f);
}

void GameOver::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_logo_game_over_1);
    window.draw(sprite_logo_game_over_2);
    window.draw(text_restart);
    window.draw(text_exit);
}