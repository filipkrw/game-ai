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
    Vector2 scale) : MovingEntity(0, position, rotation, velocity, mass, maxSpeed, maxForce, maxTurnRate, scale)
{
    m_pWorld = world;
}

void Vehicle::Update(double dt)
{
}
