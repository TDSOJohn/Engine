#include "ResourceHolder.hpp"
#include "ResourcePath.hpp"
#include "ResourceIdentifiers.hpp"
#include "Utility.hpp"

#include "GUI/Container.hpp"
#include "GUI/Button.hpp"
#include "GUI/InputField.hpp"

#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>
#include <memory>
#include <functional>
#include <vector>


sf::Vector2f pos_old;
float dis_old;

sf::Vector2f pos_new;
float dis_new;


sf::Vector2f getDirection()
{
    sf::Vector2f result;
    result = { pos_new.x  - pos_old.x, pos_new.y  - pos_old.y };

    return result;
}

float getAngle()
{
    sf::Vector2f dir = getDirection();
    if(dir.x == 0)
        return 0.f;

    float result = std::asin(-dir.y / eng::length(dir));
    return result;
}


int main()
{
    pos_old = pos_new = { 0, 0 };
    dis_old = dis_new = 0;

    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "GUI window");

    //  Create sfml window and set framerate limit to 60
//    sf::RenderWindow window(modes[0], "GUI window", sf::Style::Fullscreen);
    window.setFramerateLimit(60.f);

    //  Create eng::TextureHolder and load the Button texture
    eng::TextureHolder text;
    text.load(eng::Textures::Buttons, "../../Resources/Textures/Buttons.png");

    //  Create eng::FontHolder and load a font
    eng::FontHolder fonts;
    fonts.load(eng::Fonts::Mono, "../../Resources/Fonts/IBMPlexMono-Regular.ttf");

    //  Create the GUI container to back buttons in
    eng::Container mGUIContainer;

    //  Create a button, set its position, text and callback function
    eng::Button button_1(fonts, text);
    button_1.setPosition(100.f, 100.f);
    button_1.setText("Start Game");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseMoved)
            {
                pos_old = pos_new;
                dis_old = dis_new;
                pos_new = { event.mouseMove.x, event.mouseMove.y };
                dis_new = eng::length(pos_new - button_1.getPosition());
                std::cout << dis_new << std::endl;

//                button_1.setPosition(button_1.getPosition() + getDirection());
                std::cout << eng::modulo(eng::toDegree(getAngle()), 360) << std::endl;
                if(dis_new > dis_old)
                    std::cout << "Getting Closer.." << std::endl;
            }
                //  Let the container handle the event
                button_1.handleEvent(event);
        }
        window.clear();
        window.draw(button_1);
        window.display();
    }
    return 0;
}
