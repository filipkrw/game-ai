#ifndef KINEMATIC_ARRIVE_H
#define KINEMATIC_ARRIVE_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "../../util/Vector2.h"

class KinematicArrive
{
public:
    KinematicArrive(KinematicEntity *character, float maxSpeed = 400.f, float maxAcceleration = 1200.f, float targetRadius = 1.f, float slowRadius = 250.f, float timeToTarget = 0.01f)
        : character(character), maxSpeed(maxSpeed), maxAcceleration(maxAcceleration), targetRadius(targetRadius), slowRadius(slowRadius), timeToTarget(timeToTarget) {}

    KinematicEntity *character;
    KinematicSteeringOutput steering;

    double maxSpeed;
    double maxAcceleration;
    double targetRadius;
    double slowRadius;
    double timeToTarget;

    void CalculateSteering(Vector2 target);
    void DrawDebug();
};

#endif // KINEMATIC_ARRIVE_H