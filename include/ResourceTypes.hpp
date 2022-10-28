#ifndef resourcetypes_hpp
#define resourcetypes_hpp

#include "ResourceIdentifiers.hpp"

#include <map>

namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class SoundBuffer;
}

namespace eng
{

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>           TextureHolder;

typedef ResourceHolder<sf::Font, Fonts::ID>                 FontHolder;

typedef ResourceHolder<sf::Shader, Shaders::ID>             ShaderHolder;

typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;

typedef std::map<Music::ID, std::string>                    MusicPathHolder;

}

#endif /* resoursetypes_hpp */