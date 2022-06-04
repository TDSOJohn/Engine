#include "Physics/RigidBody.hpp"
#include "Utility.hpp"

#include <cmath>
#include <iostream>


namespace eng
{

RigidBody::RigidBody(float maxv):
    maxVelocity(maxv),
    mMass(0.f),
    mVelocity(0.f),
    mAcceleration(0.f, 0.f),
    mRotation(0.f)
{
    computeDirectedVelocity(0.f);
}

void RigidBody::setVelocity(float v)
{
    mVelocity = v;
    mVelocity *= -1;
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

float RigidBody::getCurrentRotation() const
{
    return toDegree(mRotation);
}

void RigidBody::computeDirectedVelocity(float deg)
{
    mRotation = toRadian(deg);

    mDirectedVelocity.x = -std::sin(mRotation) * mVelocity;
    mDirectedVelocity.y = std::cos(mRotation) * mVelocity;
}

sf::Vector2f RigidBody::getDirectedVelocity() const
{
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
