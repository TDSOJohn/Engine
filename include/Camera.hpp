#pragma once

#include <SFML/Graphics.hpp>

namespace eng
{


class Camera: public sf::View
{
public:
    explicit            Camera();

    void                setSmoothing(float s_in);
    void                update(const sf::Time& dt);
    void                setTargetPosition(const sf::Vector2f& pos_in);

    // Expects 0..359 degrees input
    void                setTargetRotation(float deg_in);

private:
    sf::Vector2f        mTargetPosition;
    float               mTargetRotation;
    float               mSmoothing;
};


}
