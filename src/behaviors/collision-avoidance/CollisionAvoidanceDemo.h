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

    // Entity *wanderEntity;
    // Wander *wander;

    BlendedSteering *blendedSteering;

    std::vector<Wanderer> wanderers;

public:
    CollisionAvoidanceDemo() : Demo()
    {
        // wanderEntity = new Entity(Vector2(500, 500), 100.f, sf::Color::Magenta);
        // wander = new Wander(wanderEntity);

        playerEntity = new Entity(Vector2(100, 100), 6000.f, sf::Color::Blue);
        blendedSteering = new BlendedSteering();

        Arrive *arrive = new Arrive(playerEntity);
        blendedSteering->AddArrive(arrive, gameWorld->crosshair, 1);

        CollisionAvoidance *collisionAvoidance = new CollisionAvoidance(playerEntity);
        blendedSteering->AddCollisionAvoidance(collisionAvoidance, 2);

        for (int i = 0; i < 100; i++)
        {
            Entity *wandererEntity = new Entity(Vector2(Util::RandomBetween(100, 900), Util::RandomBetween(100, 900)), 50.f, sf::Color::Red);
            Wander *w = new Wander(wandererEntity);
            BlendedSteering *wandererSteering = new BlendedSteering();
            wandererSteering->AddWander(w, 1);
            wanderers.push_back({wandererEntity, wandererSteering});

            collisionAvoidance->targets.push_back(wandererEntity);
        }
    };

    void Update(double dt)
    {
        SteeringOutput mainEntitySteering = blendedSteering->GetSteering();
        playerEntity->Update(mainEntitySteering, dt);

        // SteeringOutput wanderEntitySteering = wander->GetSteering();
        // wanderEntity->Update(wanderEntitySteering, dt);

        for (auto &wanderer : wanderers)
        {
            SteeringOutput wandererSteering = wanderer.steering->GetSteering();
            wanderer.entity->Update(wandererSteering, dt);
        }
    }

    void Render()
    {
        playerEntity->Render();
        // wanderEntity->Render();

        for (auto &wanderer : wanderers)
        {
            wanderer.entity->Render();
        }
    };
};

#endif // COLLISIONAVOIDANCE_DEMO_H