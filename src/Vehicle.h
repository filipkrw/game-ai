#ifndef VEHICLE_H
#define VEHICLE_H

#include "MovingEntity.h"
#include "SteeringBehaviors.h"

class GameWorld;
class SteeringBehaviors;

class Vehicle : public MovingEntity
{
private:
    GameWorld *m_pWorld;
    SteeringBehaviors *m_pSteering;

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

    void Render();

    SteeringBehaviors *const Steering() const { return m_pSteering; }

    GameWorld *const World() const { return m_pWorld; }
};

#endif // VEHICLE_H
