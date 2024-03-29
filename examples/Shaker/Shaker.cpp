#include "ResourceHolder.hpp"
#include "ResourceTypes.hpp"
#include "ResourcePath.hpp"
#include "ResourceIdentifiers.hpp"

#include "Camera.hpp"
#include "SpriteNode.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <functional>


int main()
{
    //  Create sfml window and set framerate limit to 60
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Shaker");
    window.setFramerateLimit(60.f);

    //  Create the background rectangle (we'll change its color later)
    sf::RectangleShape background(sf::Vector2f(1920, 1080));
    background.setFillColor(sf::Color(0, 0, 0));

    //  Create eng::TextureHolder and load the Button texture
    eng::TextureHolder mTextures;
    mTextures.load(eng::Textures::Background, eng::getResourcePath() + "Textures/Background.jpg");

    //  Create eng::FontHolder and load a font
    eng::FontHolder fonts;
    fonts.load(eng::Fonts::QuinqueFive, eng::getResourcePath() + "Fonts/QuinqueFive.ttf");

    eng::Camera mCamera;
    mCamera.setTargetPosition({960.f, 540.f});

    eng::SceneNode mSceneGraph;
    std::unique_ptr<eng::SpriteNode> backgroundNode(new eng::SpriteNode(mTextures.get(eng::Textures::ID::Background)));
    backgroundNode->setPosition(0.f, 0.f);
    mSceneGraph.attachChild(std::move(backgroundNode));

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                    mCamera.shake(rand()%10 + 1);
        }
        mCamera.update(dt);
        window.clear();

        window.draw(mSceneGraph);

        window.setView(mCamera);

        window.display();
    }
    return 0;
}
