#ifndef ResourceIdentifiers_hpp
#define ResourceIdentifiers_hpp

namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class SoundBuffer;
}

namespace eng
{

namespace Textures
{
    enum ID
    {
        TitleBar,
        Title,

        Background,
        Tileset,
        Planet,
        Raptor,
        Eagle,
        Health,
        Missile,
        Spread,
        Rate,
        ImprovedAmmo,
        Enemy_1,
        Enemy_2,
        Enemy_360,
        Npc,
        BasicBullet,
        BulletFmj,
        Bullet_2,
        Bullet_3,
        Won,
        Lost,
        Buttons,
        Particle,
        Explosion,
    };
}

namespace Fonts
{
    enum ID
    {
        Mono,
        Cursive,
        Standard
    };
}

namespace Shaders
{
    enum ID
    {
        BrightnessPass,
        DownSamplePass,
        GaussianBlurPass,
        AddPass,
    };
}

namespace SoundEffect
{
    enum ID
    {
        AlliedGunfire,
        EnemyGunfire,
        Explosion1,
        Explosion2,
        LaunchMissile,
        CollectPickup,
        Button,
    };
}

namespace Music
{
    enum ID
    {
        MenuTheme,
        MissionTheme,
    };
}


// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>           TextureHolder;

typedef ResourceHolder<sf::Font, Fonts::ID>                 FontHolder;

typedef ResourceHolder<sf::Shader, Shaders::ID>             ShaderHolder;

typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;

typedef std::map<Music::ID, std::string>                    MusicPathHolder;


}

#endif /* ResourceIdentifiers_hpp */
