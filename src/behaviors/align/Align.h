#ifndef ALIGN_H
#define ALIGN_H

#include "../common/Steering.h"

class Align : public Steering
{
public:
    Align(Entity *character) : Steering(character){};

    double maxAngularAcceleration = 1000;
    double maxRotation = 7.5;

    double targetRadius = 0.02;
    double slowRadius = 0.8;

    double timeToTarget = 0.01;

    SteeringOutput GetSteering(double orientation);
};

#endif // ALIGN_H