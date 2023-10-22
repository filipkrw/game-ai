#ifndef COLLISIONAVOIDANCE_DEMO_H
#define COLLISIONAVOIDANCE_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "CollisionAvoidance.h"
#include "../look-ahead/LookAhead.h"
#include "../arrive/Arrive.h"
#include "../../util/Util.h"

class CollisionAvoidanceDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;

    std::vector<Entity *> collisionavoidanceEntities;
    std::vector<CollisionAvoidance *> collisionavoidances;

public:
    CollisionAvoidanceDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(100, 100), 6000.f, sf::Color::Red);
        arrive = new Arrive(arriveEntity);

        for (int i = 0; i < 1; i++)
        {
            Entity *entity = new Entity(
                Vector2(Util::RandomBetween(250, 750), Util::RandomBetween(250, 750)),
                Vector2(Util::RandomBetween(-50, -100), Util::RandomBetween(-50, -100)));
            collisionavoidanceEntities.push_back(entity);

            CollisionAvoidance *collisionavoidance = new CollisionAvoidance(entity);

            // for (Entity *target : collisionavoidanceEntities)
            // {
            //     collisionavoidance->targets.push_back(target);
            // }
            collisionavoidance->targets.push_back(arriveEntity);

            collisionavoidances.push_back(collisionavoidance);
        }
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;

        SteeringOutput arriveSteering = arrive->GetSteering(crosshairPosition);
        arriveEntity->Update(arriveSteering, dt);

        for (int i = 0; i < collisionavoidanceEntities.size(); i++)
        {
            Entity *entity = collisionavoidanceEntities[i];
            CollisionAvoidance *collisionavoidance = collisionavoidances[i];

            SteeringOutput collisionavoidanceSteering = collisionavoidance->GetSteering();
            entity->Update(collisionavoidanceSteering, dt);
        }
    }

    void Render()
    {
        arriveEntity->Render();

        for (Entity *entity : collisionavoidanceEntities)
        {
            entity->Render();
            entity->DrawDebug();
        }

        arriveEntity->DrawDebug();
    };
};

#endif // COLLISIONAVOIDANCE_DEMO_H