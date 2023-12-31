#ifndef BLENDED_STEERING_H
#define BLENDED_STEERING_H

#include "../Entity.h"
#include "../StaticEntity.h"
#include "../Steering.h"
#include "../../arrive/Arrive.h"
#include "../../collision-avoidance/CollisionAvoidance.h"
#include "../../wander/Wander.h"
#include "../../../util/Vector2.h"

class BlendedSteering
{
public:
    struct ArriveBehavior
    {
        Arrive *behavior;
        StaticEntity *target;
        double weight;
    };

    struct WanderBehavior
    {
        Wander *behavior;
        double weight;
    };

    struct CollisionAvoidanceBehavior
    {
        CollisionAvoidance *behavior;
        double weight;
    };

    std::vector<ArriveBehavior> arriveBehaviors;
    std::vector<WanderBehavior> wanderBehaviors;
    std::vector<CollisionAvoidanceBehavior> collisionAvoidanceBehaviors;

    float maxAcceleration;

public:
    BlendedSteering(){};

    void AddArrive(Arrive *arrive, StaticEntity *target, double weight)
    {
        arriveBehaviors.push_back({arrive, target, weight});
    }

    void AddWander(Wander *wander, double weight)
    {
        wanderBehaviors.push_back({wander, weight});
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

        for (auto &baw : wanderBehaviors)
        {
            SteeringOutput steering = baw.behavior->GetSteering();
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