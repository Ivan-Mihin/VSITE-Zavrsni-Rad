#include "audio.h"

Audio::Audio() {}

Audio& Audio::getInstance()
{
    static Audio instance;
    return instance;
}

void Audio::load()
{
    // load resources later
}

void Audio::playSound(const std::string& name)
{
    // add later
}

void Audio::playMusic(const std::string& name)
{
    // add later
}