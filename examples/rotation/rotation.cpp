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

    for(int i = 0; i < 10; i++)
    {
        mCamera.update(sf::Time::Zero);
        std::cout << mCamera.getRotation() << "\t\t";
    }

    return 0;
}
