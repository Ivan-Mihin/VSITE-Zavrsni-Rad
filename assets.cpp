#include "assets.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdexcept>
#include <string>

Assets::Assets() {}

Assets& Assets::getInstance()
{
    static Assets instance;
    return instance;
}

void Assets::load()
{
    try
    {
        // Textures
        if (!textures["background"].loadFromFile("Assets/Textures/background.png"))
            throw std::runtime_error("Failed to load background.png");
        if (!textures["board"].loadFromFile("Assets/Textures/board.png"))
            throw std::runtime_error("Failed to load board.png");
        if (!textures["game_over_line"].loadFromFile("Assets/Textures/game_over_line.png"))
            throw std::runtime_error("Failed to load game_over_line.png");
        if (!textures["logo_game_over_1"].loadFromFile("Assets/Textures/logo_game_over_1.png"))
            throw std::runtime_error("Failed to load logo_game_over_1.png");
        if (!textures["logo_game_over_2"].loadFromFile("Assets/Textures/logo_game_over_2.png"))
            throw std::runtime_error("Failed to load logo_game_over_2.png");
        if (!textures["logo_tetris"].loadFromFile("Assets/Textures/logo_tetris.png"))
            throw std::runtime_error("Failed to load logo_tetris.png");
        if (!textures["tetromino"].loadFromFile("Assets/Textures/tetromino.png"))
            throw std::runtime_error("Failed to load tetromino.png");
        if (!textures["tetromino_ghost"].loadFromFile("Assets/Textures/tetromino_ghost.png"))
            throw std::runtime_error("Failed to load tetromino_ghost.png");

        // Fonts
        if (!fonts["BaiJamjuree-Regular"].openFromFile("Assets/Fonts/BaiJamjuree-Regular.ttf"))
            throw std::runtime_error("Failed to load BaiJamjuree-Regular.ttf");

        // Sounds
        if (!sounds["all_clear"].loadFromFile("Assets/Audio/Sounds/all_clear.ogg"))
            throw std::runtime_error("Failed to load all_clear.ogg");
        if (!sounds["clear_four_lines"].loadFromFile("Assets/Audio/Sounds/clear_four_lines.ogg"))
            throw std::runtime_error("Failed to load clear_four_lines.ogg");
        if (!sounds["clear_line"].loadFromFile("Assets/Audio/Sounds/clear_line.ogg"))
            throw std::runtime_error("Failed to load clear_line.ogg");
        if (!sounds["combo_1"].loadFromFile("Assets/Audio/Sounds/combo_1.ogg"))
            throw std::runtime_error("Failed to load combo_1.ogg");
        if (!sounds["combo_2"].loadFromFile("Assets/Audio/Sounds/combo_2.ogg"))
            throw std::runtime_error("Failed to load combo_2.ogg");
        if (!sounds["combo_3"].loadFromFile("Assets/Audio/Sounds/combo_3.ogg"))
            throw std::runtime_error("Failed to load combo_3.ogg");
        if (!sounds["combo_4"].loadFromFile("Assets/Audio/Sounds/combo_4.ogg"))
            throw std::runtime_error("Failed to load combo_4.ogg");
        if (!sounds["combo_5"].loadFromFile("Assets/Audio/Sounds/combo_5.ogg"))
            throw std::runtime_error("Failed to load combo_5.ogg");
        if (!sounds["combo_6"].loadFromFile("Assets/Audio/Sounds/combo_6.ogg"))
            throw std::runtime_error("Failed to load combo_6.ogg");
        if (!sounds["combo_7"].loadFromFile("Assets/Audio/Sounds/combo_7.ogg"))
            throw std::runtime_error("Failed to load combo_7.ogg");
        if (!sounds["combo_8"].loadFromFile("Assets/Audio/Sounds/combo_8.ogg"))
            throw std::runtime_error("Failed to load combo_8.ogg");
        if (!sounds["combo_9"].loadFromFile("Assets/Audio/Sounds/combo_9.ogg"))
            throw std::runtime_error("Failed to load combo_9.ogg");
        if (!sounds["combo_10"].loadFromFile("Assets/Audio/Sounds/combo_10.ogg"))
            throw std::runtime_error("Failed to load combo_10.ogg");
        if (!sounds["combo_11"].loadFromFile("Assets/Audio/Sounds/combo_11.ogg"))
            throw std::runtime_error("Failed to load combo_11.ogg");
        if (!sounds["combo_12"].loadFromFile("Assets/Audio/Sounds/combo_12.ogg"))
            throw std::runtime_error("Failed to load combo_12.ogg");
        if (!sounds["combo_13"].loadFromFile("Assets/Audio/Sounds/combo_13.ogg"))
            throw std::runtime_error("Failed to load combo_13.ogg");
        if (!sounds["combo_14"].loadFromFile("Assets/Audio/Sounds/combo_14.ogg"))
            throw std::runtime_error("Failed to load combo_14.ogg");
        if (!sounds["combo_15"].loadFromFile("Assets/Audio/Sounds/combo_15.ogg"))
            throw std::runtime_error("Failed to load combo_15.ogg");
        if (!sounds["combo_16"].loadFromFile("Assets/Audio/Sounds/combo_16.ogg"))
            throw std::runtime_error("Failed to load combo_16.ogg");
        if (!sounds["combo_break"].loadFromFile("Assets/Audio/Sounds/combo_break.ogg"))
            throw std::runtime_error("Failed to load combo_break.ogg");
        if (!sounds["floor"].loadFromFile("Assets/Audio/Sounds/floor.ogg"))
            throw std::runtime_error("Failed to load floor.ogg");
        if (!sounds["hard_drop"].loadFromFile("Assets/Audio/Sounds/hard_drop.ogg"))
            throw std::runtime_error("Failed to load hard_drop.ogg");
        if (!sounds["hold"].loadFromFile("Assets/Audio/Sounds/hold.ogg"))
            throw std::runtime_error("Failed to load hold.ogg");
        if (!sounds["move"].loadFromFile("Assets/Audio/Sounds/move.ogg"))
            throw std::runtime_error("Failed to load move.ogg");
        if (!sounds["rotate"].loadFromFile("Assets/Audio/Sounds/rotate.ogg"))
            throw std::runtime_error("Failed to load rotate.ogg");

        // Music
        music["tetirs_theme_song"] = "Assets/Audio/Music/tetris_theme_song.ogg";

    }
    catch (const std::exception& e)
    {
        std::cerr << "Asset load error: " << e.what() << "\n";
        throw;
    }
}

const sf::Texture& Assets::getTexture(const std::string& name) const
{
    return textures.at(name);
}

const sf::Font& Assets::getFont(const std::string& name) const
{
    return fonts.at(name);
}

const sf::SoundBuffer& Assets::getSound(const std::string& name) const
{
    return sounds.at(name);
}

const std::string& Assets::getMusic(const std::string& name) const
{
    return music.at(name);
}