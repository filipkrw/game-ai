#ifndef VEHICLE_H
#define VEHICLE_H

#include "MovingEntity.h"
#include "SteeringBehaviors.h"

class GameWorld;
class SteeringBehaviors;

typedef struct VehicleParams
{
    Vector2 initialPosition = Vector2(450, 300);
    Vector2 scale = Vector2(1, 1);
    double mass = 0.1;
    double maxSpeed = 200;
    double maxForce = 500;
    double maxTurnRate = M_PI;
    double boundingRadius = 10;
} VehicleParams;

class Vehicle : public MovingEntity
{
private:
    GameWorld *m_pWorld;
    SteeringBehaviors *m_pSteering;

public:
    Vehicle(GameWorld *world, VehicleParams params);

    void Update(double dt);
    void Render();

    SteeringBehaviors *const Steering() const { return m_pSteering; }
    GameWorld *const World() const { return m_pWorld; }
};

#endif // VEHICLE_H
