#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(
    GameWorld *world,
    Vector2 position,
    double rotation,
    Vector2 velocity,
    double mass,
    double maxSpeed,
    double maxForce,
    double maxTurnRate,
    Vector2 scale) : MovingEntity(0)
{
    m_pWorld = world;
    m_vPosition = position;
    m_dRotation = rotation;
    m_vVelocity = velocity;
    m_dMass = mass;
    m_dMaxSpeed = maxSpeed;
    m_dMaxForce = maxForce;
    m_dMaxTurnRate = maxTurnRate;
    m_vScale = scale;
}

Vehicle::Vehicle() : MovingEntity(0)
{
    std::cout << "Vehicle::Vehicle()" << std::endl;
}

void Vehicle::Update(double dt)
{
}
