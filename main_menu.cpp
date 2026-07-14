#include "assets.h"
#include "main_menu.h"

MainMenu::MainMenu() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
    sprite_logo(Assets::getInstance().getTexture("logo_tetris")),
    text_start(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    text_exit(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    sprite_background.setPosition({ 0, 0 });

    sprite_logo.setOrigin({ 250, 0 });
    sprite_logo.setPosition({ 400, 50 });

    textUpdate(text_start, "Start", 50, 400.f, 550.f);
    textUpdate(text_exit, "Exit", 50, 400.f, 630.f);

    selected = MainMenuItem::Start;

    current_text_start_size = max_size;
    current_text_exit_size = default_size;

    target_text_start_size = max_size;
    target_text_exit_size = default_size;
}

void MainMenu::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });
}

void MainMenu::textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
}

void MainMenu::textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y)
{
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
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
            selected = MainMenuItem::Start;

            target_text_start_size = max_size;
            target_text_exit_size = default_size;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            selected = MainMenuItem::Exit;

            target_text_start_size = default_size;
            target_text_exit_size = max_size;
        }
    }
}

void MainMenu::update(float delta_time)
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

    textUpdate(text_start, current_text_start_size, 400.f, 550.f);
    textUpdate(text_exit, current_text_exit_size, 400.f, 630.f);
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(sprite_logo);
    window.draw(text_start);
    window.draw(text_exit);
}