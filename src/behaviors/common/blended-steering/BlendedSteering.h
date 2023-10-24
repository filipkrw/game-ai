#ifndef BLENDED_STEERING_H
#define BLENDED_STEERING_H

#include "../Entity.h"
#include "../StaticEntity.h"
#include "../Steering.h"
#include "../../arrive/Arrive.h"
#include "../../../util/Vector2.h"
#include "../../collision-avoidance/CollisionAvoidance.h"

class BlendedSteering
{
public:
    struct ArriveBehavior
    {
        Arrive *behavior;
        StaticEntity *target;
        double weight;
    };

    struct CollisionAvoidanceBehavior
    {
        CollisionAvoidance *behavior;
        double weight;
    };

    std::vector<ArriveBehavior> arriveBehaviors;
    std::vector<CollisionAvoidanceBehavior> collisionAvoidanceBehaviors;

    float maxAcceleration;

public:
    BlendedSteering(){};

    void AddArrive(Arrive *arrive, StaticEntity *target, double weight)
    {
        arriveBehaviors.push_back({arrive, target, weight});
    }

    void AddCollisionAvoidance(CollisionAvoidance *collisionAvoidance, double weight)
    {
        collisionAvoidanceBehaviors.push_back({collisionAvoidance, weight});
    }

    SteeringOutput GetSteering()
    {
        SteeringOutput totalSteering;

        for (auto &baw : arriveBehaviors)
        {
            SteeringOutput steering = baw.behavior->GetSteering(baw.target->position);
            totalSteering.velocity += steering.velocity * baw.weight;
            totalSteering.rotation += steering.rotation * baw.weight;
        }

        for (auto &baw : collisionAvoidanceBehaviors)
        {
            SteeringOutput steering = baw.behavior->GetSteering();
            totalSteering.velocity += steering.velocity * baw.weight;
            totalSteering.rotation += steering.rotation * baw.weight;
        }

        // totalSteering.velocity = Vector2::Truncate(totalSteering.velocity, maxAcceleration);

        return totalSteering;
    }
};

#endif // BLENDED_STEERING_H