#ifndef ALIGN_H
#define ALIGN_H

#include "../common/Steering.h"

class Align : public Steering
{
public:
    Align(Entity *character) : Steering(character){};

    double maxAngularAcceleration = 3;
    double maxRotation = 1.5;

    double targetRadius = 0.01;
    double slowRadius = 0.5;

    double timeToTarget = 0.1;

    void CalculateSteering(double orientation);
};

#endif // ALIGN_H