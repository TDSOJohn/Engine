#include "Physics/RigidBody.hpp"
#include "Utility.hpp"

#include <iostream>

void printRigidBody(eng::RigidBody& rb_in)
{
    std::cout << "\n\nRigid Body information:\n";
    std::cout << "\nMass: " << rb_in.getMass();
    std::cout << "\nVelocity: " << rb_in.getVelocity();
    std::cout << "\nRotation: " << rb_in.getCurrentRotation();

    sf::Vector2f dirVel = rb_in.getDirectedVelocity();
    std::cout << "\nDirected Velocity: " << dirVel.x << " " << dirVel.y << std::endl;
}


int main()
{
    //  Create rigidBody with max velocity of 100
    eng::RigidBody rb(100.f);

    std::cout << "\nRigid Body created";

    printRigidBody(rb);

    std::cout << "\nRotating 45 degrees...";
    //  rotate 45 degrees
    rb.computeDirectedVelocity(45.f);

    printRigidBody(rb);

    std::cout << "\nSetting velocity to 100...";
    // set velocity to 100
    rb.setVelocity(100.f);

    printRigidBody(rb);

    std::cout << "\nRotating -90 degrees...";
    rb.computeDirectedVelocity(-90.f);

    printRigidBody(rb);

    return 0;
}
