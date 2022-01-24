#include "Button.hpp"

class BetterButton : public Button
{
public:
    BetterButton(const FontHolder& fonts, const TextureHolder& textures):
        Button(fonts, textures)
    {
    }

    virtual void            handleEvent(const sf::Event& event);

private:
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
}
