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


//  A simple function that changes the color of the input sf::RectangleShape to random values
void changeColor(sf::RectangleShape& rect_in)
{
    rect_in.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
}

//  A simple function that prints a 0..99 random number to the std output
void randomNumber()
{
    std::cout << rand()%100 << std::endl;
}


int main()
{
    //  Create sfml window and set framerate limit to 60
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GUI window");
    window.setFramerateLimit(60.f);

    //  Create the background rectangle (we'll change its color later)
    sf::RectangleShape background(sf::Vector2f(1280, 720));
    background.setFillColor(sf::Color(0, 0, 0));

    //  Create eng::TextureHolder and load the Button texture
    eng::TextureHolder text;
    text.load(eng::Textures::Buttons, eng::getResourcePath() + "Textures/Buttons.png");
    text.load(eng::Textures::InputField, eng::getResourcePath() + "Textures/InputField.png");

    //  Create eng::FontHolder and load a font
    eng::FontHolder fonts;
    fonts.load(eng::Fonts::Mono, eng::getResourcePath() + "Fonts/Mono.ttf");

    //  Create the GUI container to store GUI elements in
    eng::Container mGUIContainer;

    //  Create a button, set its position, text and callback function
    auto button_1 = std::make_shared<eng::Button>(fonts, eng::Fonts::Mono, text, eng::Textures::Buttons);
    button_1->setPosition(100.f, 100.f);
    button_1->setText("Random\nNumber!");
    button_1->setCallback(randomNumber);

    //  Pack it inside the container
    mGUIContainer.pack(button_1);

    //  Create a button, set its position, text and callback function
    auto button_2 = std::make_shared<eng::Button>(fonts, eng::Fonts::Mono, text, eng::Textures::Buttons);
    button_2->setPosition(100.f, 250.f);
    button_2->setText("Change\nColor!");
    //  Use std::ref as a copyable reference wrapper to pass to changeSize
    //  See https://stackoverflow.com/questions/26187192/how-to-bind-function-to-an-object-by-reference
    button_2->setCallback(std::bind(changeColor, std::ref(background)));

    //  Pack it inside the container
    mGUIContainer.pack(button_2);

    //  Create a button, set its position, text and callback function
    auto button_3 = std::make_shared<eng::Button>(fonts, eng::Fonts::Mono, text, eng::Textures::Buttons);
    button_3->setPosition(100.f, 400.f);
    button_3->setText("Useless\nbutton!");
    
    //  Pack it inside the container
    mGUIContainer.pack(button_3);

    //  Create an input field, set its position
    auto input_1 = std::make_shared<eng::InputField>(fonts, eng::Fonts::Mono, text, eng::Textures::InputField, "Insert text");
    input_1->setPosition(100.f, 550.f);

    //  Pack it inside the container
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
        //  Draw the background
        window.draw(background);
        //  Draw the container
        window.draw(mGUIContainer);
        window.display();
    }
    return 0;
}
