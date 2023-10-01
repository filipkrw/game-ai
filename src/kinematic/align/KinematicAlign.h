#ifndef KINEMATICALIGN_H
#define KINEMATICALIGN_H

#include "../common/KinematicSteering.h"

typedef struct KinematicAlignParams
{
    double maxAngularAcceleration = 3;
    double maxRotation = 1.5;

    double targetRadius = 0.01;
    double slowRadius = 0.5;

    double timeToTarget = 0.1;
} KinematicAlignParams;

class KinematicAlign : public KinematicSteering
{
public:
    KinematicAlign(KinematicEntity *character) : KinematicSteering(character)
    {
        KinematicAlignParams params = KinematicAlignParams();
        KinematicAlign(character, &params);
    };

    KinematicAlign(KinematicEntity *character, KinematicAlignParams *params) : KinematicSteering(character)
    {
        this->maxAngularAcceleration = params->maxAngularAcceleration;
        this->maxRotation = params->maxRotation;
        this->targetRadius = params->targetRadius;
        this->slowRadius = params->slowRadius;
        this->timeToTarget = params->timeToTarget;
    };

    double maxAngularAcceleration;
    double maxRotation;

    double targetRadius;
    double slowRadius;

    double timeToTarget;

    void CalculateSteering(double orientation);
};

#endif // KINEMATICALIGN_H