//
//  DataTables.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 10/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//
/*
#include "DataTables.hpp"

#include "Core/Particle.hpp"
#include "Core/Utility.hpp"

#include "Spaceship.hpp"
#include "Projectile.hpp"
#include "Pickup.hpp"

#include <cmath>


// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

std::vector<SpaceshipData> initializeSpaceshipData()
{
    std::vector<SpaceshipData> data(Spaceship::Typecount);

    //  Randomly generated speed and fire interval
    std::vector<int> partition = generatePartition(100, 2);
    data[Spaceship::Old_Fart].hitpoints = 100;
    data[Spaceship::Old_Fart].speed = 500.f;
    data[Spaceship::Old_Fart].fireInterval = sf::seconds(0.012 * static_cast<float>(partition[1]));
    data[Spaceship::Old_Fart].texture = Textures::Eagle;
    data[Spaceship::Old_Fart].textureRect = sf::IntRect(0, 0, 64, 119);
    data[Spaceship::Old_Fart].hasRollAnimation = false;

    data[Spaceship::Flying_Hippo].hitpoints = 150;
    data[Spaceship::Flying_Hippo].speed = 350.f;
    data[Spaceship::Flying_Hippo].fireInterval = sf::seconds(1);
    data[Spaceship::Flying_Hippo].texture = Textures::Eagle;
    data[Spaceship::Flying_Hippo].textureRect = sf::IntRect(0, 0, 64, 119);
    data[Spaceship::Flying_Hippo].hasRollAnimation = false;

    data[Spaceship::Speed_Junkie].hitpoints = 70;
    data[Spaceship::Speed_Junkie].speed = 700.f;
    data[Spaceship::Speed_Junkie].fireInterval = sf::seconds(1);
    data[Spaceship::Speed_Junkie].texture = Textures::Eagle;
    data[Spaceship::Speed_Junkie].textureRect = sf::IntRect(0, 0, 64, 119);
    data[Spaceship::Speed_Junkie].hasRollAnimation = false;

    data[Spaceship::Psychedelic_Space_Teapot].hitpoints = 130;
    data[Spaceship::Psychedelic_Space_Teapot].speed = 400.f;
    data[Spaceship::Psychedelic_Space_Teapot].fireInterval = sf::seconds(1);
    data[Spaceship::Psychedelic_Space_Teapot].texture = Textures::Eagle;
    data[Spaceship::Psychedelic_Space_Teapot].textureRect = sf::IntRect(0, 0, 64, 119);
    data[Spaceship::Psychedelic_Space_Teapot].hasRollAnimation = false;

    data[Spaceship::Enemy_1].hitpoints = 60;
    data[Spaceship::Enemy_1].speed = 200.f;
    data[Spaceship::Enemy_1].fireInterval = sf::seconds(1.3f);
    data[Spaceship::Enemy_1].texture = Textures::Enemy_1;
    data[Spaceship::Enemy_1].textureRect = sf::IntRect(0, 0, 65, 64);
    data[Spaceship::Enemy_1].directions.push_back(Direction(180.f, 300.f));
    data[Spaceship::Enemy_1].directions.push_back(Direction(270.f, 300.f));
    data[Spaceship::Enemy_1].directions.push_back(Direction(0.f, 300.f));
    data[Spaceship::Enemy_1].directions.push_back(Direction(90.f, 300.f));
    data[Spaceship::Enemy_1].hasRollAnimation = false;

    data[Spaceship::Enemy_2].hitpoints = 40;
    data[Spaceship::Enemy_2].speed = 300.f;
    data[Spaceship::Enemy_2].fireInterval = sf::seconds(2.f);
    data[Spaceship::Enemy_2].texture = Textures::Enemy_2;
    data[Spaceship::Enemy_2].directions.push_back(Direction(240.f, 300.f));
    data[Spaceship::Enemy_2].directions.push_back(Direction(120.f, 300.f));
    data[Spaceship::Enemy_2].directions.push_back(Direction(0.f, 300.f));
    data[Spaceship::Enemy_2].textureRect = sf::IntRect(0, 0, 65, 64);
    data[Spaceship::Enemy_2].hasRollAnimation = false;

    data[Spaceship::Npc].hitpoints = 100;
    data[Spaceship::Npc].speed = 0.f;
    data[Spaceship::Npc].fireInterval = sf::Time::Zero;
    data[Spaceship::Npc].texture = Textures::Npc;
    data[Spaceship::Npc].textureRect = sf::IntRect(0, 0, 64, 119);
    data[Spaceship::Npc].hasRollAnimation = false;

    return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
    std::vector<ProjectileData> data(Projectile::TypeCount);

    data[Projectile::AlliedBullet].damage = 10;
    data[Projectile::AlliedBullet].speed = 600.f;
    data[Projectile::AlliedBullet].texture = Textures::Bullet_1;
    data[Projectile::AlliedBullet].textureRect = sf::IntRect(0, 0, 8, 32);

    data[Projectile::EnemyBullet].damage = 10;
    data[Projectile::EnemyBullet].speed = 500.f;
    data[Projectile::EnemyBullet].texture = Textures::Bullet_2;
    data[Projectile::EnemyBullet].textureRect = sf::IntRect(0, 0, 8, 32);

    data[Projectile::Missile].damage = 200;
    data[Projectile::Missile].speed = 150.f;
    data[Projectile::Missile].texture = Textures::Bullet_3;
    data[Projectile::Missile].textureRect = sf::IntRect(0, 0, 35, 104);

    return data;
}

std::vector<PickupData> initializePickupData()
{
    std::vector<PickupData> data(Pickup::TypeCount);

    data[Pickup::HealthRefill].texture = Textures::Health;
    data[Pickup::HealthRefill].action = std::bind(&Spaceship::repair, _1, 25);
    data[Pickup::HealthRefill].textureRect = sf::IntRect(0, 0, 18, 28);


    data[Pickup::MissileRefill].texture = Textures::Missile;
    data[Pickup::MissileRefill].action = std::bind(&Spaceship::collectMissiles, _1, 3);
    data[Pickup::MissileRefill].textureRect = sf::IntRect(0, 0, 18, 28);

    data[Pickup::FireSpread].texture = Textures::Spread;
    data[Pickup::FireSpread].action = std::bind(&Spaceship::increaseSpread, _1);
    data[Pickup::FireSpread].textureRect = sf::IntRect(0, 0, 32, 32);

    data[Pickup::FireRate].texture = Textures::Rate;
    data[Pickup::FireRate].action = std::bind(&Spaceship::increaseFireRate, _1);
    data[Pickup::FireRate].textureRect = sf::IntRect(0, 0, 32, 32);

    return data;
}

std::vector<ParticleData> initializeParticleData()
{
    std::vector<ParticleData> data(Particle::ParticleCount);

    data[Particle::Propellant].color = sf::Color(255, 255, 50);
    data[Particle::Propellant].lifetime = sf::seconds(0.6f);

    data[Particle::Smoke].color = sf::Color(50, 50, 50);
    data[Particle::Smoke].lifetime = sf::seconds(4.f);

    return data;
}*/
