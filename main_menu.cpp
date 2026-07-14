#include "assets.h"
#include "main_menu.h"

MainMenu::MainMenu() :
    background(Assets::getInstance().getTexture("background_main_menu")),
    logo(Assets::getInstance().getTexture("logo_tetris")),
    start(Assets::getInstance().getFont("BaiJamjuree-Regular")),
    exit(Assets::getInstance().getFont("BaiJamjuree-Regular"))
{
    background.setPosition({ 0, 0 });

    logo.setOrigin({ 250, 0 });
    logo.setPosition({ 400, 50 });

    textUpdate(start, "Start", 50, 400.f, 550.f);
    textUpdate(exit, "Exit", 50, 400.f, 630.f);

    selected = MenuItem::Start;

    current_start_size = max_size;
    current_exit_size = default_size;

    target_start_size = max_size;
    target_exit_size = default_size;
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

MenuItem MainMenu::getSelectedMenuItem() const
{
    return selected;
}

void MainMenu::handleInput(const sf::Event& event)
{
    if (const auto* key = event.getIf<sf::Event::KeyPressed>()) 
    {
        if (key->scancode == sf::Keyboard::Scancode::Up)
        {
            selected = MenuItem::Start;

            target_start_size = max_size;
            target_exit_size = default_size;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            selected = MenuItem::Exit;

            target_start_size = default_size;
            target_exit_size = max_size;
        }
    }
}

void MainMenu::update(float delta_time)
{
    float animation_speed = 150.f;

    if (current_start_size < target_start_size)
    {
        current_start_size += animation_speed * delta_time;

        if (current_start_size > target_start_size) current_start_size = max_size;
    }

    if (current_start_size > target_start_size)
    {
        current_start_size -= animation_speed * delta_time;

        if (current_start_size < target_start_size) current_start_size = default_size;
    }

    if (current_exit_size < target_exit_size)
    {
        current_exit_size += animation_speed * delta_time;

        if (current_exit_size > target_exit_size) current_exit_size = max_size;
    }

    if (current_exit_size > target_exit_size)
    {
        current_exit_size -= animation_speed * delta_time;

        if (current_exit_size < target_exit_size) current_exit_size = default_size;
    }

    textUpdate(start, current_start_size, 400.f, 550.f);
    textUpdate(exit, current_exit_size, 400.f, 630.f);
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(logo);
    window.draw(start);
    window.draw(exit);
}