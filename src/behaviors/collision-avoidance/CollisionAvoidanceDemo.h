#ifndef COLLISIONAVOIDANCE_DEMO_H
#define COLLISIONAVOIDANCE_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "CollisionAvoidance.h"
#include "../look-ahead/LookAhead.h"
#include "../arrive/Arrive.h"
#include "../../util/Util.h"
#include "../common/blended-steering/BlendedSteering.h"
#include "../wander/Wander.h"

class CollisionAvoidanceDemo : public Demo
{
private:
    struct Wanderer
    {
        Entity *entity;
        BlendedSteering *steering;
    };

    Entity *playerEntity;

    BlendedSteering *blendedSteering;

    std::vector<Wanderer> wanderers;

public:
    CollisionAvoidanceDemo() : Demo()
    {
        playerEntity = new Entity(Vector2(5, 5), 60000.f, sf::Color::Blue);
        blendedSteering = new BlendedSteering();

        Arrive *arrive = new Arrive(playerEntity);
        blendedSteering->AddArrive(arrive, gameWorld->crosshair, 1);

        CollisionAvoidance *collisionAvoidance = new CollisionAvoidance(playerEntity);
        blendedSteering->AddCollisionAvoidance(collisionAvoidance, 2);

        int numWanderers = 100;

        for (int i = 0; i < numWanderers; i++)
        {
            Entity *wandererEntity = new Entity(Vector2(Util::RandomBetween(100, 900), Util::RandomBetween(100, 900)), 50.f, sf::Color::Red);
            Wander *w = new Wander(wandererEntity);
            BlendedSteering *wandererSteering = new BlendedSteering();
            wandererSteering->AddWander(w, 1);
            wanderers.push_back({wandererEntity, wandererSteering});

            collisionAvoidance->targets.push_back(wandererEntity);
        }

        for (int i = 0; i < numWanderers; i++)
        {
            CollisionAvoidance *ca = new CollisionAvoidance(wanderers[i].entity);

            for (int j = 0; j < numWanderers; j++)
            {
                if (i == j)
                    continue;
                ca->targets.push_back(wanderers[j].entity);
            }

            ca->targets.push_back(playerEntity);
            wanderers[i].steering->AddCollisionAvoidance(ca, 2);
        }
    };

    void Update(double dt)
    {
        SteeringOutput mainEntitySteering = blendedSteering->GetSteering();
        playerEntity->Update(mainEntitySteering, dt);

        for (auto &wanderer : wanderers)
        {
            SteeringOutput wandererSteering = wanderer.steering->GetSteering();
            wanderer.entity->Update(wandererSteering, dt);
        }
    }

    void Render()
    {
        playerEntity->Render();

        for (auto &wanderer : wanderers)
        {
            wanderer.entity->Render();
        }
    };
};

#endif // COLLISIONAVOIDANCE_DEMO_H