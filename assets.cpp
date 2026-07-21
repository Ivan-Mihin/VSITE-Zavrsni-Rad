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
        if (!sounds["clear_line"].loadFromFile("Assets/Audio/Sounds/clear_line.ogg"))
            throw std::runtime_error("Failed to load clear_line.ogg");
        if (!sounds["combo_break"].loadFromFile("Assets/Audio/Sounds/combo_break.ogg"))
            throw std::runtime_error("Failed to load combo_break.ogg");
        if (!sounds["floor"].loadFromFile("Assets/Audio/Sounds/floor.ogg"))
            throw std::runtime_error("Failed to load floor.ogg");
        if (!sounds["hard_drop"].loadFromFile("Assets/Audio/Sounds/hard_drop.ogg"))
            throw std::runtime_error("Failed to load hard_drop.ogg");
        if (!sounds["move"].loadFromFile("Assets/Audio/Sounds/move.ogg"))
            throw std::runtime_error("Failed to load move.ogg");
        if (!sounds["navigation"].loadFromFile("Assets/Audio/Sounds/navigation.ogg"))
            throw std::runtime_error("Failed to load navigation.ogg");
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