#ifndef _ARRIVE_H
#define _ARRIVE_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "../../util/Vector2.h"

class Arrive
{
public:
    Arrive(Entity *character) : character(character){};

    Entity *character;
    SteeringOutput steering;

    double maxSpeed = 400.f;
    double maxAcceleration = 300.f;
    double maxDeceleration = 1500.f;
    double targetRadius = 1.f;
    double slowRadius = 200.f;
    double timeToTarget = 0.05f;

    void CalculateSteering(Vector2 target);
    void DrawDebug();
};

#endif // _ARRIVE_H