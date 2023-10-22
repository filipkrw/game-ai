#ifndef SEPARATION_H
#define SEPARATION_H

#include "../common/Entity.h"
#include "../common/Steering.h"
#include "../common/SteeringOutput.h"
#include "../look-ahead/LookAhead.h"

class Separation : LookAhead
{
public:
    std::vector<Entity *> targets;

    double maxAcceleration = 20000.f;
    double threshold = 200.f;
    double decayCoefficient = 1000000.f;

public:
    Separation(Entity *character) : LookAhead(character) {}
    SteeringOutput GetSteering();
};

#endif // SEPARATION_H