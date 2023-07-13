#ifndef STEERING_BEHAVIORS_H
#define STEERING_BEHAVIORS_H

#include "util/Vector2.h"
// #include "Vehicle.h"

class Vehicle;

class SteeringBehaviors
{
private:
    Vehicle *m_pVehicle;

public:
    SteeringBehaviors(Vehicle *vehicle);

    Vector2 Seek(Vector2 targetPos);
    Vector2 Flee(Vector2 targetPos, double panicDistance = -1.0f);
};

#endif // STEERING_BEHAVIORS_H