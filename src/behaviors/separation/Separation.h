#ifndef SEPARATION_H
#define SEPARATION_H

#include "../common/Entity.h"
#include "../common/Steering.h"
#include "../common/SteeringOutput.h"

class Separation : public Steering
{
public:
    std::vector<Entity *> targets;

    double maxAcceleration = 200.f;
    double threshold = 50.f;
    double decayCoefficient = 1000000.f;

public:
    Separation(Entity *character) : Steering(character) {}
    SteeringOutput GetSteering();
};

#endif // SEPARATION_H