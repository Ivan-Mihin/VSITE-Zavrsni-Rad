#pragma once

#include <SFML/Audio.hpp>

#include <string>
#include <unordered_map>

class Audio
{
private:
    Audio();

    std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;
    sf::Music music;

public:
    Audio(const Audio&) = delete;
    Audio& operator=(const Audio&) = delete;

    static Audio& getInstance();

    void playSound(const std::string& name);
    void playMusic(const std::string& name);
};