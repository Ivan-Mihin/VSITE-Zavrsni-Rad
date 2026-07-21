#include "assets.h"
#include "audio.h"

#include <string>

Audio::Audio() {}

void Audio::cleanFinishedSounds()
{
    for (int i = active_sounds.size() - 1; i >= 0; --i)
    {
        if (active_sounds[i].getStatus() == sf::Sound::Status::Stopped)
        {
            active_sounds.erase(active_sounds.begin() + i);
        }
    }
}

Audio& Audio::getInstance()
{
    static Audio instance;
    return instance;
}

void Audio::update()
{
    cleanFinishedSounds();
}

void Audio::playSound(const std::string& name)
{
    const sf::SoundBuffer& buffer = Assets::getInstance().getSound(name);
    active_sounds.emplace_back(buffer);
    active_sounds.back().play();
}

void Audio::playMusic(const std::string& name)
{
    std::string filepath = Assets::getInstance().getMusic(name);

    if (music.openFromFile(filepath))
    {
        music.setVolume(music_volume);
        music.setLooping(true);
        music.play();
    }
}

void Audio::volumeUp(float volume_change)
{
    music_volume = std::clamp(music_volume + volume_change, 0.0f, 100.0f);
    music.setVolume(music_volume);
}

void Audio::volumeDown(float volume_change)
{
    music_volume = std::clamp(music_volume - volume_change, 0.0f, 100.0f);
    music.setVolume(music_volume);
}