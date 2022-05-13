#include "Physics/rigidBody.hpp"
#include "Utility.hpp"

#include <iostream>

void printRigidBody(eng::RigidBody& rb_in)
{
    std::cout << "\n\nRigid Body information:\n";
    std::cout << "\nMass: " << rb_in.getMass();
    std::cout << "\nVelocity: " << rb_in.getVelocity();
    std::cout << "\nRotation: " << rb_in.getCurrentRotation();

    sf::Vector2f dirVel = rb_in.getDirectedVelocity(rb_in.getCurrentRotation());
    std::cout << "\nDirected Velocity: " << dirVel.x << " " << dirVel.y << std::endl;
}


int main()
{
    //  Create rigidBody with max velocity of 100
    eng::RigidBody rb(100.f);

    std::cout << "Rigid Body created";

    printRigidBody(rb);

    //  rotate 45 degrees
    rb.getDirectedVelocity(45.f);

    printRigidBody(rb);

    // set velocity to 100
    rb.setVelocity(100.f);

    printRigidBody(rb);

    rb.getDirectedVelocity(-90.f);

    printRigidBody(rb);

    return 0;
}
