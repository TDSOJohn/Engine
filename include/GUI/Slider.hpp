#ifndef slider_hpp
#define slider_hpp

#include "GUI/Component.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace eng
{

class Slider: public Component
{
public:
    /// Create std::shared_ptr<Button> with Button::Ptr syntax.
    typedef std::shared_ptr<Slider>     Ptr;
    typedef std::function<void()>       Callback;

    enum Scale
    {
        Linear,
        Logarithmic,
        ScaleCount
    };

    enum Type
    {
        Normal,
        Selected,
        Pressed,
        ButtonCount
    };

public:
                            Slider(const sf::Font& font_in, int min_val = 0, int max_val = 100);
//  Let's consider only the int slider for now
//    explicit                Slider(float min_val = 0.f, float max_val = 100.f);

    void                    setCallback(Callback callback);
    bool                    isSelectable() const;

    virtual void            select();
    virtual void            deselect();

    virtual void            activate();
    virtual void            deactivate();

    virtual void            handleEvent(const sf::Event& event);

    int                     getValue();

    sf::FloatRect           getLocalBounds();
    sf::FloatRect           getGlobalBounds();

private:
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    changeTexture(Type SliderType);

private:
    Callback                mCallback;

    sf::CircleShape         mCursor;
    sf::RectangleShape      mSlider;

    sf::Text                mMin;
    sf::Text                mMax;

    int                     mCurrValue;
};

}

#endif //slider_hpp
