//
//  ResourceIdentifiers.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 14/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef ResourceIdentifiers_h
#define ResourceIdentifiers_h

namespace sf
{
    class Texture;
    class Font;
    class Shader;
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

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>   TextureHolder;

typedef ResourceHolder<sf::Font, Fonts::ID>         FontHolder;

typedef ResourceHolder<sf::Shader, Shaders::ID>     ShaderHolder;

}

#endif /* ResourceIdentifiers_h */
