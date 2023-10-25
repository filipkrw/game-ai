#ifndef COLLISION_AVODIANCE_H
#define COLLISION_AVODIANCE_H

#include "../common/Entity.h"
#include "../look-ahead/LookAhead.h"

// https://www.gameaipro.com/GameAIPro2/GameAIPro2_Chapter19_Guide_to_Anticipatory_Collision_Avoidance.pdf
class CollisionAvoidance : public LookAhead
{
public:
    double maxAcceleration = 3000.f;
    double radius = 100.f;

    std::vector<Entity *> targets;

public:
    CollisionAvoidance(Entity *character) : LookAhead(character){};

    SteeringOutput GetSteering();
    void DrawDebug();

private:
    double GetTimeToCollision(Entity *target);
};

#endif // COLLISION_AVODIANCE_H