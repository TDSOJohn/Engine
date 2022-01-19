#include "ResourceHolder.hpp"
#include "ResourcePath.hpp"
#include "ResourceIdentifiers.hpp"

#include "GUI/Container.hpp"
#include "GUI/Button.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <functional>


void changeSize(sf::RenderWindow& window_in)
{
    window_in.setSize(sf::Vector2u(rand()%640 + 640, rand()%360 + 360));
}

void randomNumber()
{
    std::cout << rand()%100 << std::endl;
}

void notSoRandom()
{
    std::cout << 420 << std::endl;
}


int main()
{
    //  Create sfml window and set framerate limit to 60
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GUI window");
    window.setFramerateLimit(60.f);

    //  Create eng::TextureHolder and load the Button texture
    eng::TextureHolder text;
    text.load(eng::Textures::Buttons, eng::getResourcePath() + "Textures/Buttons.png");

    //  Create eng::FontHolder and load a font
    eng::FontHolder fonts;
    fonts.load(eng::Fonts::Mono, eng::getResourcePath() + "Fonts/IBMPlexMono-Regular.ttf");

    //  Create the GUI container to back buttons in
    eng::Container mGUIContainer;

    //  Create a button, set its position, text and callback function
    auto button_1 = std::make_shared<eng::Button>(fonts, text);
    button_1->setPosition(100.f, 80.f);
    button_1->setText("Random\nNumber!");
    button_1->setCallback(randomNumber);

    //  Pack it inside the container
    mGUIContainer.pack(button_1);

    //  Create a button, set its position, text and callback function
    auto button_2 = std::make_shared<eng::Button>(fonts, text);
    button_2->setPosition(100.f, 200.f);
    button_2->setText("Something\nelse!");
    button_2->setCallback(notSoRandom);

    //  Pack it inside the container
    mGUIContainer.pack(button_2);

    //  Create a button, set its position, text and callback function
    auto button_3 = std::make_shared<eng::Button>(fonts, text);
    button_3->setPosition(100.f, 320.f);
    button_3->setText("Window\nResize!");
    //  Use std::ref as a copyable reference wrapper to pass to changeSize
    //  See https://stackoverflow.com/questions/26187192/how-to-bind-function-to-an-object-by-reference
    button_3->setCallback(std::bind(changeSize, std::ref(window)));

    //  Pack it inside the container
    mGUIContainer.pack(button_3);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            else
                //  Let the container handle the event
                mGUIContainer.handleEvent(event);
        }
        window.clear();
        window.draw(mGUIContainer);
        window.display();
    }
    return 0;
}
