#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>


namespace eng
{

class RigidBody
{
public:
    RigidBody(float maxv = 0.f);

    void                    setVelocity(float v);

    void                    accelerate(float v);

    void                    elasticCollision(sf::Vector2f force);

    float                   getVelocity() const;

    float                   getCurrentRotation() const;

    //  input: rotation in degrees [0, ..., 360]
    //  necessary because RigidBody doesn't inherit sf::Transformable
    //  Not const because it updates mDirectedVelocity before returning
    sf::Vector2f            getDirectedVelocity(float deg);
    float                   getMaxVelocity() const;

    float                   getMass() const;
    sf::Vector2f            getForce() const;

protected:
    float                   mMass;

    float                   mVelocity;
    sf::Vector2f            mDirectedVelocity;
    float                   maxVelocity;

    sf::Vector2f            mAcceleration;

    //  rotation in radians
    float                   mRotation;
};
}

#endif
