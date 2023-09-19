#ifndef KINEMATICALIGN_H
#define KINEMATICALIGN_H

#include "../common/KinematicSteering.h"

class KinematicAlign : public KinematicSteering
{
public:
    KinematicAlign(KinematicEntity *character) : KinematicSteering(character){};

    double maxAngularAcceleration = 3;
    double maxRotation = 1.5;

    double targetRadius = 0.01;
    double slowRadius = 0.5;

    double timeToTarget = 0.1;

    void CalculateSteering(double orientation);
};

#endif // KINEMATICALIGN_H