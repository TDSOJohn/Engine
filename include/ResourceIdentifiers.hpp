#ifndef ResourceIdentifiers_hpp
#define ResourceIdentifiers_hpp

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

}

#endif /* ResourceIdentifiers_hpp */
