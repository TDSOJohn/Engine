#include "Physics/RigidBody.hpp"
#include "Utility.hpp"

#include <cmath>


namespace eng
{

RigidBody::RigidBody(float maxv):
    maxVelocity(maxv)
{
    getDirectedVelocity(0.f);
}

void RigidBody::setVelocity(float v)
{
    mVelocity = v;
}

void RigidBody::accelerate(float velocity)
{
    mVelocity += velocity;
}

void RigidBody::elasticCollision(sf::Vector2f force)
{
    sf::Vector2f mForce = getForce();
    //  INSERT ELASTIC COLLISION CODE HERE
}

float RigidBody::getVelocity() const
{
    return mVelocity;
}

sf::Vector2f RigidBody::getDirectedVelocity(float deg)
{
    float rad = toRadian(deg);
    mDirectedVelocity.x = -std::sin(rad) * mVelocity;
    mDirectedVelocity.y = std::cos(rad) * mVelocity;

    return mDirectedVelocity;
}

float RigidBody::getMaxVelocity() const
{
    return maxVelocity;
}

float RigidBody::getMass() const
{
    return mMass;
}

sf::Vector2f RigidBody::getForce() const
{
    return sf::Vector2f(mMass * mDirectedVelocity.x, mMass * mDirectedVelocity.y);
}

}
