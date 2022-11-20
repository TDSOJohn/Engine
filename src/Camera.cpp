#include "Camera.hpp"
#include "Utility.hpp"

#include <iostream>
#include <cmath>

namespace eng
{


Camera::Camera():
    sf::View(sf::Vector2f(0.f, 0.f) , sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height)),
    mTargetPosition(0.f, 0.f),
    mTargetRotation(0.f),
    mSmoothing(10.f),
    mShakeRadius(0.f)
{
}

void Camera::setSmoothing(float s_in)
{
    mSmoothing = s_in;
}

void Camera::update(const sf::Time& dt)
{
    //  Get position to follow
    sf::Vector2f mCurrentPosition = sf::View::getCenter() - mShakeOffset;
    sf::Vector2f mMovement = (mTargetPosition - mCurrentPosition) / mSmoothing;

    sf::View::setCenter(mCurrentPosition + mMovement);

    float start = sf::View::getRotation();
    bool rotDir = rotationDirection(start, mTargetRotation);
    float diff = 0.f;

    if(std::abs(start - mTargetRotation) >= 180.f)
        diff = (360 - std::abs(start - mTargetRotation));
    else
        diff = std::abs(start - mTargetRotation);

    if(rotDir)
        sf::View::setRotation(start + diff / mSmoothing);
    else
        sf::View::setRotation(start - diff / mSmoothing);

    int angle = rand() % 360;
    float rad = eng::toRadian(angle);
    mShakeOffset = {std::sin(rad), std::cos(rad)};
    mShakeOffset *= mShakeRadius;
    mShakeRadius *= 0.9;

    sf::View::setCenter(mCurrentPosition + mShakeOffset);
}

void Camera::setTargetPosition(const sf::Vector2f& pos_in)
{
    mTargetPosition = pos_in;
}

void Camera::setTargetRotation(float deg_in)
{
    mTargetRotation = deg_in;
}

void Camera::shake(float strength)
{
    if(strength < 0.f || strength > 10.f)
        return;

    mShakeRadius += (sf::View::getSize().x / 100.f) * strength;
}


}
