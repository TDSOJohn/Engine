//
// Created by Giovanni Basso on 28/06/22.
//

#include <MusicPlayer.hpp>
#include "ResourcePath.hpp"

namespace eng
{

MusicPlayer::MusicPlayer()
        : mMusic()
        , mFilenames()
        , mVolume(100.f)
{
    mFilenames[Music::MenuTheme]    = getResourcePath() + "Music/MenuTheme.ogg";
    mFilenames[Music::MissionTheme] = getResourcePath() + "Music/Tense.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
    std::string filename = mFilenames[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + " could not be loaded.");

    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();
}

void MusicPlayer::stop()
{
    mMusic.stop();
}

void MusicPlayer::setVolume(float volume)
{
    mVolume = volume;
}

void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}

}