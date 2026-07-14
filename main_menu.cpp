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

    textInitialize(start, "Start", 50, 400.f, 550.f);
    textInitialize(exit, "Exit", 50, 400.f, 630.f);

    selected = MenuItem::Start;
}

void MainMenu::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });
}

MenuItem MainMenu::getSelectedMenuItem() const 
{
    return selected;
}

void MainMenu::textInitialize(sf::Text& text, std::string string, int char_size, float pos_x, float pos_y)
{
    text.setString(string);
    text.setCharacterSize(char_size);
    sf::FloatRect bounds = text.getLocalBounds();
    centerText(text);
    text.setPosition({ pos_x, pos_y });
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
    float speed = 150.f;

    if (current_start_size < target_start_size)
    {
        current_start_size += speed * delta_time;

        if (current_start_size > target_start_size)
            current_start_size = max_size;
    }

    if (current_start_size > target_start_size)
    {
        current_start_size -= speed * delta_time;

        if (current_start_size < target_start_size)
            current_start_size = default_size;
    }

    if (current_exit_size < target_exit_size)
    {
        current_exit_size += speed * delta_time;

        if (current_exit_size > target_exit_size)
            current_exit_size = max_size;
    }

    if (current_exit_size > target_exit_size)
    {
        current_exit_size -= speed * delta_time;

        if (current_exit_size < target_exit_size)
            current_exit_size = default_size;
    }

    start.setCharacterSize(static_cast<unsigned int>(current_start_size));
    exit.setCharacterSize(static_cast<unsigned int>(current_exit_size));

    centerText(start);
    centerText(exit);

    start.setPosition({ 400.f, 550.f });
    exit.setPosition({ 400.f, 630.f });
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(logo);
    window.draw(start);
    window.draw(exit);
}