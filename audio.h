#pragma once

#include <SFML/Audio.hpp>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Audio
{
private:
    Audio();

    std::vector<std::unique_ptr<sf::Sound>> active_sounds;
    sf::Music music;

    float music_volume = 20.f;

    void cleanFinishedSounds();

public:
    Audio(const Audio&) = delete;
    Audio& operator=(const Audio&) = delete;

    static Audio& getInstance();

    void update();
    void playSound(const std::string& name);
    void playMusic(const std::string& name);
    void volumeUp(float volume_change);
    void volumeDown(float volume_change);
};