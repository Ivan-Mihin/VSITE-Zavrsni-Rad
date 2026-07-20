#include "assets.h"
#include "audio.h"

#include <string>

Audio::Audio() {}

Audio& Audio::getInstance()
{
    static Audio instance;
    return instance;
}

void Audio::playSound(const std::string& name)
{
    Assets::getInstance().getSound(name);
}

void Audio::playMusic(const std::string& name)
{
    Assets::getInstance().getMusic(name);
}