#ifndef ARRIVE_H
#define ARRIVE_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "../../util/Vector2.h"
#include "../look-ahead/LookAhead.h"

class Arrive : public LookAhead
{
public:
    Arrive(Entity *character) : LookAhead(character){};

    double maxSpeed = 400.f;
    double maxAcceleration = 300.f;
    double maxDeceleration = 1500.f;
    double targetRadius = 1.f;
    double slowRadius = 200.f;
    double timeToTarget = 0.05f;

    SteeringOutput GetSteering(Vector2 target);
    void DrawDebug();
};

#endif // ARRIVE_H