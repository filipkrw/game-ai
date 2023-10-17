#ifndef ALIGN_H
#define ALIGN_H

#include "../common/Steering.h"

class Align : public Steering
{
public:
    Align(Entity *character) : Steering(character){};

    double maxAngularAcceleration = 3000;
    double maxRotation = 15;

    double targetRadius = 0.02;
    double slowRadius = 0.4;

    double timeToTarget = 0.01;

    SteeringOutput GetSteering(double orientation);
};

#endif // ALIGN_H