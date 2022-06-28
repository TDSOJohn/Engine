//
// Created by Giovanni Basso on 28/06/22.
//

#ifndef NOGRAVITAR_MUSICPLAYER_HPP
#define NOGRAVITAR_MUSICPLAYER_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


namespace eng
{

class MusicPlayer : private sf::NonCopyable
{
public:
    MusicPlayer();

    void play(Music::ID theme);

    void stop();

    void setPaused(bool paused);

    void setVolume(float volume);


private:
    sf::Music mMusic;
    std::map<Music::ID, std::string> mFilenames;
    float mVolume;
};

}
#endif //NOGRAVITAR_MUSICPLAYER_HPP
