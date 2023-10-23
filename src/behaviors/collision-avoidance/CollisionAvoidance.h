#ifndef COLLISION_AVODIANCE_H
#define COLLISION_AVODIANCE_H

#include "../common/Entity.h"
#include "../look-ahead/LookAhead.h"

class CollisionAvoidance : public LookAhead
{
public:
    double maxAcceleration = 500.f;
    double radius = 100.f;

    std::vector<Entity *> targets;

public:
    CollisionAvoidance(Entity *character) : LookAhead(character){};

    SteeringOutput GetSteering();
    void DrawDebug();
};

#endif // COLLISION_AVODIANCE_H