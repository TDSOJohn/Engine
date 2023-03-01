//
//  Utility.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 10/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "SpriteNode.hpp"
#include "Utility.hpp"
#include "Animation.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <random>
#include <cmath>
#include <ctime>
#include <cassert>


namespace
{
    std::default_random_engine createRandomEngine()
    {
        auto seed = static_cast<unsigned long>(std::time(nullptr));
        return std::default_random_engine(seed);
    }

    auto RandomEngine = createRandomEngine();
}

namespace eng
{

Pixel::Pixel():
    r(0),
    g(0),
    b(0),
    a(0)
{
}

Pixel::Pixel(const Pixel& pxl_in):
    r(pxl_in.r),
    g(pxl_in.g),
    b(pxl_in.b),
    a(pxl_in.a)
{
}

unsigned int modulo(int value, int m)
{
    if(m == 0)
        return value;

    int mod = value % m;
    if(mod < 0)
        mod += m;
    return mod;
}

std::string toString(sf::Keyboard::Key key)
{
    #define BOOK_KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

    switch (key)
    {
        BOOK_KEYTOSTRING_CASE(Unknown)
        BOOK_KEYTOSTRING_CASE(A)
        BOOK_KEYTOSTRING_CASE(B)
        BOOK_KEYTOSTRING_CASE(C)
        BOOK_KEYTOSTRING_CASE(D)
        BOOK_KEYTOSTRING_CASE(E)
        BOOK_KEYTOSTRING_CASE(F)
        BOOK_KEYTOSTRING_CASE(G)
        BOOK_KEYTOSTRING_CASE(H)
        BOOK_KEYTOSTRING_CASE(I)
        BOOK_KEYTOSTRING_CASE(J)
        BOOK_KEYTOSTRING_CASE(K)
        BOOK_KEYTOSTRING_CASE(L)
        BOOK_KEYTOSTRING_CASE(M)
        BOOK_KEYTOSTRING_CASE(N)
        BOOK_KEYTOSTRING_CASE(O)
        BOOK_KEYTOSTRING_CASE(P)
        BOOK_KEYTOSTRING_CASE(Q)
        BOOK_KEYTOSTRING_CASE(R)
        BOOK_KEYTOSTRING_CASE(S)
        BOOK_KEYTOSTRING_CASE(T)
        BOOK_KEYTOSTRING_CASE(U)
        BOOK_KEYTOSTRING_CASE(V)
        BOOK_KEYTOSTRING_CASE(W)
        BOOK_KEYTOSTRING_CASE(X)
        BOOK_KEYTOSTRING_CASE(Y)
        BOOK_KEYTOSTRING_CASE(Z)
        BOOK_KEYTOSTRING_CASE(Num0)
        BOOK_KEYTOSTRING_CASE(Num1)
        BOOK_KEYTOSTRING_CASE(Num2)
        BOOK_KEYTOSTRING_CASE(Num3)
        BOOK_KEYTOSTRING_CASE(Num4)
        BOOK_KEYTOSTRING_CASE(Num5)
        BOOK_KEYTOSTRING_CASE(Num6)
        BOOK_KEYTOSTRING_CASE(Num7)
        BOOK_KEYTOSTRING_CASE(Num8)
        BOOK_KEYTOSTRING_CASE(Num9)
        BOOK_KEYTOSTRING_CASE(Escape)
        BOOK_KEYTOSTRING_CASE(LControl)
        BOOK_KEYTOSTRING_CASE(LShift)
        BOOK_KEYTOSTRING_CASE(LAlt)
        BOOK_KEYTOSTRING_CASE(LSystem)
        BOOK_KEYTOSTRING_CASE(RControl)
        BOOK_KEYTOSTRING_CASE(RShift)
        BOOK_KEYTOSTRING_CASE(RAlt)
        BOOK_KEYTOSTRING_CASE(RSystem)
        BOOK_KEYTOSTRING_CASE(Menu)
        BOOK_KEYTOSTRING_CASE(LBracket)
        BOOK_KEYTOSTRING_CASE(RBracket)
        BOOK_KEYTOSTRING_CASE(SemiColon)
        BOOK_KEYTOSTRING_CASE(Comma)
        BOOK_KEYTOSTRING_CASE(Period)
        BOOK_KEYTOSTRING_CASE(Quote)
        BOOK_KEYTOSTRING_CASE(Slash)
        BOOK_KEYTOSTRING_CASE(BackSlash)
        BOOK_KEYTOSTRING_CASE(Tilde)
        BOOK_KEYTOSTRING_CASE(Equal)
        BOOK_KEYTOSTRING_CASE(Dash)
        BOOK_KEYTOSTRING_CASE(Space)
        BOOK_KEYTOSTRING_CASE(Return)
        BOOK_KEYTOSTRING_CASE(BackSpace)
        BOOK_KEYTOSTRING_CASE(Tab)
        BOOK_KEYTOSTRING_CASE(PageUp)
        BOOK_KEYTOSTRING_CASE(PageDown)
        BOOK_KEYTOSTRING_CASE(End)
        BOOK_KEYTOSTRING_CASE(Home)
        BOOK_KEYTOSTRING_CASE(Insert)
        BOOK_KEYTOSTRING_CASE(Delete)
        BOOK_KEYTOSTRING_CASE(Add)
        BOOK_KEYTOSTRING_CASE(Subtract)
        BOOK_KEYTOSTRING_CASE(Multiply)
        BOOK_KEYTOSTRING_CASE(Divide)
        BOOK_KEYTOSTRING_CASE(Left)
        BOOK_KEYTOSTRING_CASE(Right)
        BOOK_KEYTOSTRING_CASE(Up)
        BOOK_KEYTOSTRING_CASE(Down)
        BOOK_KEYTOSTRING_CASE(Numpad0)
        BOOK_KEYTOSTRING_CASE(Numpad1)
        BOOK_KEYTOSTRING_CASE(Numpad2)
        BOOK_KEYTOSTRING_CASE(Numpad3)
        BOOK_KEYTOSTRING_CASE(Numpad4)
        BOOK_KEYTOSTRING_CASE(Numpad5)
        BOOK_KEYTOSTRING_CASE(Numpad6)
        BOOK_KEYTOSTRING_CASE(Numpad7)
        BOOK_KEYTOSTRING_CASE(Numpad8)
        BOOK_KEYTOSTRING_CASE(Numpad9)
        BOOK_KEYTOSTRING_CASE(F1)
        BOOK_KEYTOSTRING_CASE(F2)
        BOOK_KEYTOSTRING_CASE(F3)
        BOOK_KEYTOSTRING_CASE(F4)
        BOOK_KEYTOSTRING_CASE(F5)
        BOOK_KEYTOSTRING_CASE(F6)
        BOOK_KEYTOSTRING_CASE(F7)
        BOOK_KEYTOSTRING_CASE(F8)
        BOOK_KEYTOSTRING_CASE(F9)
        BOOK_KEYTOSTRING_CASE(F10)
        BOOK_KEYTOSTRING_CASE(F11)
        BOOK_KEYTOSTRING_CASE(F12)
        BOOK_KEYTOSTRING_CASE(F13)
        BOOK_KEYTOSTRING_CASE(F14)
        BOOK_KEYTOSTRING_CASE(F15)
        BOOK_KEYTOSTRING_CASE(Pause)
        //  -->IMPROVE<--
        //  warning now silenced, but default break does not make any sense here
        default:
            break;
    }

    return "";
}

void centerOrigin(sf::Sprite& sprite)
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

void centerOrigin(Animation& animation)
{
    sf::FloatRect bounds = animation.getLocalBounds();
    animation.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

void centerOrigin(SpriteNode& sprite)
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(std::floor(bounds.width / 2.f), std::floor(bounds.height / 2.f));
}

float toDegree(float radian)
{
    return (180.f / 3.141592653589793238462643383f) * radian;
}

float toRadian(float degree)
{
    return (3.141592653589793238462643383f / 180.f) * degree;
}

bool rotationDirection(float start, float end)
{
    if(std::sin(toRadian(start) - toRadian(end)) > 0)
        return 0;
    else
        return 1;
}

float length(sf::Vector2f vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f distance(sf::Vector2f v1, sf::Vector2f v2)
{
    sf::Vector2f result;
    result.x = v2.x - v1.x;
    result.y = v2.y - v1.y;
    return result;
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
    if(vector == sf::Vector2f(0.f, 0.f))
        vector = {100.f, 100.f};
//    assert(vector != sf::Vector2f(0.f, 0.f));
    return vector / length(vector);
}

int randomInt(int exclusiveMax)
{
    std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
    return distr(RandomEngine);
}

std::vector<int> generatePartition(int max_n, unsigned int parts)
{
    float bias[parts];
    float total = 0;

    for(int i = 0; i < parts; i++)
    {
        bias[i] = rand() % 101;
        total += bias[i];
    }

    std::vector<int> part;
    for(int i = 0; i < parts; i++)
        part.push_back(std::round(static_cast<float>(max_n) * (bias[i] / total)));

    return part;
}

Pixel inverse(const Pixel& in)
{
    Pixel res;
    res.r = 255 - in.r;
    res.g = 255 - in.g;
    res.b = 255 - in.b;
    return res;
}

sf::Vector2f directedVector(float deg)
{
    float rad = toRadian(deg);
    sf::Vector2f result(std::sin(rad), -std::cos(rad));

    return result;
}

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
    unsigned int category1 = colliders.first->getCategory();
    unsigned int category2 = colliders.second->getCategory();

    // check if first pair entry has category type1 and second has type2
    if (type1 & category1 && type2 & category2)
    {
        return true;
    }
    else if (type1 & category2 && type2 & category1)
    {
        std::swap(colliders.first, colliders.second);
        return true;
    }
    else
    {
        return false;
    }
}

}
