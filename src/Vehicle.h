#ifndef VEHICLE_H
#define VEHICLE_H

#include "MovingEntity.h"
// #include "SteeringBehaviors.h"

class GameWorld;
// class SteeringBehaviors;

class Vehicle : MovingEntity
{
private:
    GameWorld *m_pWorld;
    // SteeringBehaviors *m_pSteering;

public:
    Vehicle(
        GameWorld *world,
        Vector2 position,
        double rotation,
        Vector2 velocity,
        double mass,
        double maxSpeed,
        double maxForce,
        double maxTurnRate,
        Vector2 scale);

    void Update(double dt);
};

#endif // VEHICLE_H
