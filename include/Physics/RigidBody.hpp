#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>


namespace eng
{

class RigidBody
{
public:
    RigidBody(float maxv = 0.f, float maxr = 0.f);

    void                    setVelocity(float v);

    void                    accelerate(float v);

    void                    elasticCollision(sf::Vector2f force);

    float                   getVelocity() const;

    float                   getCurrentRotation() const;
    float                   getMaxRotation() const;
    void                    setMaxRotation(float r);

    void                    rotateDeg(float deg);

    //  input: rotation in degrees [0, ..., 360]
    //  necessary because RigidBody doesn't inherit sf::Transformable
    void                    computeDirectedVelocity(float deg);

    sf::Vector2f            getDirectedVelocity() const;

    float                   getMaxVelocity() const;

    float                   getMass() const;
    sf::Vector2f            getForce() const;

protected:
    float                   mMass;

    float                   mVelocity;
    sf::Vector2f            mDirectedVelocity;
    float                   maxVelocity;

    float                   maxRotation;

    sf::Vector2f            mAcceleration;

    //  rotation in radians
    float                   mRotation;
    float                   mRotationSpeed;
};
}

#endif
