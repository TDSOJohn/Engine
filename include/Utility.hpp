//
//  Utility.hpp
//  Engine
//

#ifndef Utility_h
#define Utility_h

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

#include <sstream>
#include <vector>


namespace sf
{
    class Sprite;
    class Text;
}

class Animation;

/** @file */

/// \struct Pixel
/// \brief Simple pixel struct containing 4 uint8_t values (r, g, b, a)
/// @var Pixel::r Red value (0..255)
/// @var Pixel::g Green value (0..255)
/// @var Pixel::b Blue value (0..255)
/// @var Pixel::a Alpha value (0..255)
struct Pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};


unsigned int modulo(int value, int m);

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string         toString(const T& value);

// Convert enumerators to strings
std::string         toString(sf::Keyboard::Key key);

// Call setOrigin() with the center of the object
void                centerOrigin(sf::Sprite& sprite);
void                centerOrigin(sf::Text& text);
void                centerOrigin(Animation& animation);

// Degree/radian conversion
float               toDegree(float radian);
float               toRadian(float degree);

// Vector operations
float               length(sf::Vector2f vector);
sf::Vector2f        distance(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f        unitVector(sf::Vector2f vector);

// Random number generation
int                 randomInt(int exclusiveMax);

// Random number partitioning
std::vector<int>    generatePartition(int max_n, unsigned int parts);

/// \brief Get the negative of a pixel value.
/// Function that takes a Pixel and returns its negative, calculated as (255 - pixel_value).
/// Only r, g and b values are affected.
/// \param in input Pixel
/// \returns negative Pixel
Pixel inverse(const Pixel& in);

#include "Utility.inl"

#endif /* Utility_h */
