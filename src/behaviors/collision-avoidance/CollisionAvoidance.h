#ifndef COLLISION_AVODIANCE_H
#define COLLISION_AVODIANCE_H

#include "../common/Entity.h"
#include "../look-ahead/LookAhead.h"

class CollisionAvoidance : public LookAhead
{
public:
    double maxAcceleration = 20000.f;
    double radius = 300.f;

    std::vector<Entity *> targets;

public:
    CollisionAvoidance(Entity *character) : LookAhead(character){};
    SteeringOutput GetSteering();
};

#endif // COLLISION_AVODIANCE_H