#ifndef STEERING_BEHAVIORS_H
#define STEERING_BEHAVIORS_H

#include "util/Vector2.h"

class Vehicle;

enum Deceleration
{
    slow = 3,
    normal = 2,
    fast = 1
};

class SteeringBehaviors
{
private:
    Vehicle *m_pVehicle;

public:
    SteeringBehaviors(Vehicle *vehicle);

    Vector2 Seek(Vector2 targetPos);
    Vector2 Flee(Vector2 targetPos, double panicDistance = -1.0f);
    Vector2 Arrive(Vector2 targetPos, Deceleration deceleration = normal);
};

#endif // STEERING_BEHAVIORS_H