#include "Camera.hpp"
#include "Utility.hpp"

#include <iostream>


int main()
{
    eng::Camera mCamera;

    std::cout << "Initial rotation: " << mCamera.getRotation() << std::endl;

    std::cout << "Going to 10 deg...\n";

    std::cout << "Direction: " << eng::rotationDirection(mCamera.getRotation(), 10.f) << "\n";

    mCamera.setTargetRotation(10.f);

    for(int i = 0; i < 12; i++)
    {
        mCamera.update(sf::Time::Zero);
        std::cout << mCamera.getRotation() << "\t\t";
    }
    std::cout << "\n\n";

    std::cout << "Going to 350 deg...\n";

    std::cout << "Direction: " << eng::rotationDirection(mCamera.getRotation(), 350.f) << "\n";

    mCamera.setTargetRotation(350.f);

    for(int i = 0; i < 12; i++)
    {
        mCamera.update(sf::Time::Zero);
        std::cout << mCamera.getRotation() << "\t\t";
    }
    std::cout << "\n\n";

    std::cout << "Going to 10 deg...\n";

    std::cout << "Direction: " << eng::rotationDirection(mCamera.getRotation(), 10.f) << "\n";

    mCamera.setTargetRotation(10.f);

    for(int i = 0; i < 12; i++)
    {
        mCamera.update(sf::Time::Zero);
        std::cout << mCamera.getRotation() << "\t\t";
    }
    std::cout << "\n\n";

    return 0;
}
