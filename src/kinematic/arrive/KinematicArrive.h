#ifndef KINEMATIC_ARRIVE_H
#define KINEMATIC_ARRIVE_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "../../util/Vector2.h"

class KinematicArrive
{
public:
    KinematicArrive(KinematicEntity *character) : character(character){};

    KinematicEntity *character;
    KinematicSteeringOutput steering;

    double maxSpeed = 400.f;
    double maxAcceleration = 300.f;
    double maxDeceleration = 1500.f;
    double targetRadius = 1.f;
    double slowRadius = 200.f;
    double timeToTarget = 0.05f;

    void CalculateSteering(Vector2 target);
    void DrawDebug();
};

#endif // KINEMATIC_ARRIVE_H