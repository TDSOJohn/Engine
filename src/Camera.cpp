#include "Camera.hpp"
#include "Utility.hpp"

#include <iostream>

namespace eng
{


Camera::Camera():
    sf::View(sf::Vector2f(0.f, 0.f) , sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height)),
    mTargetPosition(0.f, 0.f),
    mTargetRotation(0.f),
    mSmoothing(10.f)
{
}

void Camera::setSmoothing(float s_in)
{
    mSmoothing = s_in;
}

void Camera::update(const sf::Time& dt)
{
    //  Get position to follow
    sf::Vector2f mCurrentPosition = sf::View::getCenter();
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
}

void Camera::setTargetPosition(const sf::Vector2f& pos_in)
{
    mTargetPosition = pos_in;
}

void Camera::setTargetRotation(float deg_in)
{
    mTargetRotation = deg_in;
}


}
