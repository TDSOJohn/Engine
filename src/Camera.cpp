#include "Camera.hpp"
//#include "Utilities.hpp"


Camera::Camera():
    sf::View(sf::Vector2f(0.f, 0.f) , sf::Vector2f(800.f, 450.f)),
    mTargetPosition(0.f, 0.f),
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
}

void Camera::setTargetPosition(const sf::Vector2f& pos_in)
{
    mTargetPosition = pos_in;
}
