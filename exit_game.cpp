#include "assets.h"
#include "exit_game.h"

ExitGame::ExitGame() :
    sprite_background(Assets::getInstance().getTexture("background_main_menu")),
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

    selected = ExitGameItem::Yes;

    current_text_yes_size = max_size;
    current_text_no_size = default_size;

    target_text_yes_size = max_size;
    target_text_no_size = default_size;
}

void ExitGame::centerText(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });
}

void ExitGame::textUpdate(sf::Text& text, std::string string, float char_size, float pos_x, float pos_y)
{
    text.setString(string);
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
}

void ExitGame::textUpdate(sf::Text& text, float char_size, float pos_x, float pos_y)
{
    text.setCharacterSize(static_cast<unsigned int>(char_size));
    centerText(text);
    text.setPosition({ pos_x, pos_y });
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

            target_text_yes_size = max_size;
            target_text_no_size = default_size;
        }

        if (key->scancode == sf::Keyboard::Scancode::Down)
        {
            selected = ExitGameItem::No;

            target_text_yes_size = default_size;
            target_text_no_size = max_size;
        }
    }
}

void ExitGame::update(float delta_time)
{
    float animation_speed = 150.f;

    if (current_text_yes_size < target_text_yes_size)
    {
        current_text_yes_size += animation_speed * delta_time;

        if (current_text_yes_size > target_text_yes_size) current_text_yes_size = max_size;
    }

    if (current_text_yes_size > target_text_yes_size)
    {
        current_text_yes_size -= animation_speed * delta_time;

        if (current_text_yes_size < target_text_yes_size) current_text_yes_size = default_size;
    }

    if (current_text_no_size < target_text_no_size)
    {
        current_text_no_size += animation_speed * delta_time;

        if (current_text_no_size > target_text_no_size) current_text_no_size = max_size;
    }

    if (current_text_no_size > target_text_no_size)
    {
        current_text_no_size -= animation_speed * delta_time;

        if (current_text_no_size < target_text_no_size) current_text_no_size = default_size;
    }

    textUpdate(text_yes, current_text_yes_size, 400.f, 550.f);
    textUpdate(text_no, current_text_no_size, 400.f, 630.f);
}

void ExitGame::render(sf::RenderWindow& window)
{
    window.draw(sprite_background);
    window.draw(text_exit);
    window.draw(text_game);
    window.draw(text_yes);
    window.draw(text_no);
}