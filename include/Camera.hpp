#pragma once

#include <SFML/Graphics.hpp>

namespace eng
{

/// \class Camera
/// \brief Simple camera class that inherits from sf::View.
///
/// Moves smoothly to target location.
/// Camera moves to 1/smoothing of the vector connecting the current sf::View location
/// to the target location and rotates 1/smoothing of the angle between
/// the camera and the target rotation
class Camera: public sf::View
{
public:
    /// \brief Constructor.
    ///
    /// Default smoothing: 10.
    explicit            Camera();

    /// \brief Set the smoothing factor.
    /// \param s_in new smoothing value.
    void                setSmoothing(float s_in);

    /// \brief updates the position and rotation according to the smoothing factor.
    /// \param dt Unused (for now) delta time. Could be used to enforce a max pixels/second
    /// velocity for the camera movement or degrees/second for the rotation.
    void                update(const sf::Time& dt);

    /// \brief set camera target position.
    /// \param pos_in sf::Vector2f containing the position to target.
    void                setTargetPosition(const sf::Vector2f& pos_in);

    /// \brief set camera target rotation.
    /// \param pos_in float containing the rotation to target in degrees [0..359].
    void                setTargetRotation(float deg_in);

private:
    sf::Vector2f        mTargetPosition;
    float               mTargetRotation;
    float               mSmoothing;
};


}
