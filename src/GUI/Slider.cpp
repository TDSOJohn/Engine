#include "GUI/Slider.hpp"

namespace eng
{


Slider::Slider(const sf::Font& font_in, int min_val, int max_val):
    mMin(min_val, )
{

}

Slider::Slider(float min_val, float max_val)
{}

void Slider::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

bool Slider::isSelectable() const
{
    return 0;
}

void Slider::select()
{}

void Slider::deselect()
{}

void Slider::activate()
{}

void Slider::deactivate()
{}

void Slider::handleEvent(const sf::Event& event)
{}

int Slider::getValue()
{

}

sf::FloatRect Slider::getLocalBounds()
{}

sf::FloatRect Slider::getGlobalBounds()
{}

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{}

void Slider::changeTexture(Type SliderType)
{}


}
