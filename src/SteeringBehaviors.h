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
    Vector2 Seek(Vector2 targetPos);
};

#endif // STEERING_BEHAVIORS_H