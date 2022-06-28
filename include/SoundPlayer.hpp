//
// Created by Giovanni Basso on 28/06/22.
//

#ifndef NOGRAVITAR_SOUNDPLAYER_HPP
#define NOGRAVITAR_SOUNDPLAYER_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>

namespace eng
{

class SoundPlayer : private sf::NonCopyable
{
public:
    SoundPlayer();

    void play(SoundEffect::ID effect);

    void play(SoundEffect::ID effect, sf::Vector2f position);

    void removeStoppedSounds();

    void setListenerPosition(sf::Vector2f position);

    sf::Vector2f getListenerPosition() const;


private:
    SoundBufferHolder mSoundBuffers;
    std::list<sf::Sound> mSounds;
};

}

#endif //NOGRAVITAR_SOUNDPLAYER_HPP
