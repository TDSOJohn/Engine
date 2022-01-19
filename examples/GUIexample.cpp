#include "ResourceHolder.hpp"
#include "ResourcePath.hpp"
#include "ResourceIdentifiers.hpp"

#include "GUI/Container.hpp"
#include "GUI/Button.hpp"
#include "GUI/InputField.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <functional>


void changeColor(sf::RectangleShape& rect_in)
{
    rect_in.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
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

    sf::RectangleShape background(sf::Vector2f(1280, 720));
    background.setFillColor(sf::Color(0, 0, 0));

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
    button_3->setText("Change\nColor!");
    //  Use std::ref as a copyable reference wrapper to pass to changeSize
    //  See https://stackoverflow.com/questions/26187192/how-to-bind-function-to-an-object-by-reference
    button_3->setCallback(std::bind(changeColor, std::ref(background)));

    //  Pack it inside the container
    mGUIContainer.pack(button_3);

    auto input_1 = std::make_shared<eng::InputField>(fonts, text, eng::InputField::Chars, "Insert text here...");
    input_1->setPosition(100.f, 440.f);

    mGUIContainer.pack(input_1);

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
        window.draw(background);
        window.draw(mGUIContainer);
        window.display();
    }
    return 0;
}
