#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Assets
{
private:
    Assets();

    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> fonts;
    std::unordered_map<std::string, sf::SoundBuffer> sounds;
    std::unordered_map<std::string, std::string> music;

public:
    Assets(const Assets&) = delete;
    Assets& operator=(const Assets&) = delete;

    static Assets& getInstance();

    void load();

    const sf::Texture& getTexture(const std::string& name) const;
    const sf::Font& getFont(const std::string& name) const;
    const sf::SoundBuffer& getSound(const std::string& name) const;
    const std::string& getMusic(const std::string& name) const;
};