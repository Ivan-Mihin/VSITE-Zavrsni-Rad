#include "audio.h"
#include "assets.h"
#include "main_menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>

MainMenu::MainMenu() :
    sprite_background(Assets::getInstance().getTexture("background")),
    sprite_logo(Assets::getInstance().getTexture("logo_tetris")),
    text_start(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_exit(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    key_bindings(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    sprite_background.setPosition({ 0, 0 });

    sprite_logo.setOrigin({ 250, 0 });
    sprite_logo.setPosition({ 400, 50 });

    textUpdate(text_start, "Start", 50, 400.f, 550.f);
    textUpdate(text_exit, "Exit", 50, 400.f, 630.f);
    textUpdate(key_bindings, "Select <Space> <Enter> - Cancel <Escape> - Volume Up <+> - Volume Down <->", 20, 400.f, 770.f);

    text_start_current_size = TEXT_MAX_SIZE;
    text_start_target_size = TEXT_MAX_SIZE;
    text_exit_current_size = TEXT_DEFAULT_SIZE;
    text_exit_target_size = TEXT_DEFAULT_SIZE;
}

void MainMenu::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
}

void MainMenu::textUpdate(sf::Text& text, std::string string, float character_size, float position_x, float position_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

void MainMenu::textUpdate(sf::Text& text, float character_size, float position_x, float position_y)
{
    text.setCharacterSize(static_cast<unsigned int>(character_size));
    centerText(text);
    text.setPosition({ position_x, position_y });
}

MainMenuItem MainMenu::getSelectedItem() const
{
    return selected;
}

void MainMenu::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>()) 
    {
        if (key->scancode == sf::Keyboard::Scancode::Up)
        {
            if (selected != MainMenuItem::Start)
            {
                Audio::getInstance().playSound("navigation");
            }

            selected = MainMenuItem::Start;

            text_start_target_size = TEXT_MAX_SIZE;
            text_exit_target_size = TEXT_DEFAULT_SIZE;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            if (selected != MainMenuItem::Exit)
            {
                Audio::getInstance().playSound("navigation");
            }

            selected = MainMenuItem::Exit;

            text_start_target_size = TEXT_DEFAULT_SIZE;
            text_exit_target_size = TEXT_MAX_SIZE;
        }
    }
}

void MainMenu::update(float delta_time)
{
    // Increase text size until it reaches max size
    if (text_start_current_size < text_start_target_size)
    {
        text_start_current_size += ANIMATION_SPEED * delta_time;

        if (text_start_current_size > text_start_target_size) text_start_current_size = TEXT_MAX_SIZE;
    }

    if (text_start_current_size > text_start_target_size)
    {
        text_start_current_size -= ANIMATION_SPEED * delta_time;

        if (text_start_current_size < text_start_target_size) text_start_current_size = TEXT_DEFAULT_SIZE;
    }

    // Decrease text size until it reaches default size
    if (text_exit_current_size < text_exit_target_size)
    {
        text_exit_current_size += ANIMATION_SPEED * delta_time;

        if (text_exit_current_size > text_exit_target_size) text_exit_current_size = TEXT_MAX_SIZE;
    }

    if (text_exit_current_size > text_exit_target_size)
    {
        text_exit_current_size -= ANIMATION_SPEED * delta_time;

        if (text_exit_current_size < text_exit_target_size) text_exit_current_size = TEXT_DEFAULT_SIZE;
    }

    textUpdate(text_start, text_start_current_size, 400.f, 550.f);
    textUpdate(text_exit, text_exit_current_size, 400.f, 630.f);
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_logo);
    window.draw(text_start);
    window.draw(text_exit);
    window.draw(key_bindings);
}