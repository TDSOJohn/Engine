#ifndef musicplayer_hpp
#define musicplayer_hpp

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <ResourceTypes.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


namespace eng
{

class MusicPlayer : private sf::NonCopyable
{
public:
    MusicPlayer(MusicPathHolder& paths);

    void play(Music::ID theme);

    void stop();

    void setPaused(bool paused);

    void setVolume(float volume);


private:
    sf::Music mMusic;
    MusicPathHolder& mFilenames;
    float mVolume;
};

}
#endif //musicplayer_hpp
