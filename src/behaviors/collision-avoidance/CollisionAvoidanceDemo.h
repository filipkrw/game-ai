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
    Entity *mainEntity;
    Arrive *arrive;
    CollisionAvoidance *collisionAvoidance;

    Entity *wanderEntity;
    Wander *wander;

    BlendedSteering *blendedSteering;

public:
    CollisionAvoidanceDemo() : Demo()
    {
        mainEntity = new Entity(Vector2(100, 100), 6000.f, sf::Color::Blue);
        wanderEntity = new Entity(Vector2(500, 500), 100.f, sf::Color::Magenta);

        collisionAvoidance = new CollisionAvoidance(mainEntity);
        collisionAvoidance->targets.push_back(wanderEntity);

        arrive = new Arrive(mainEntity);
        wander = new Wander(wanderEntity);

        blendedSteering = new BlendedSteering();
        blendedSteering->AddArrive(arrive, gameWorld->crosshair, 2);
        blendedSteering->AddCollisionAvoidance(collisionAvoidance, 1);
    };

    void Update(double dt)
    {
        SteeringOutput mainEntitySteering = blendedSteering->GetSteering();
        mainEntity->Update(mainEntitySteering, dt);

        SteeringOutput wanderEntitySteering = wander->GetSteering();
        wanderEntity->Update(wanderEntitySteering, dt);
    }

    void Render()
    {
        mainEntity->Render();
        wanderEntity->Render();

        collisionAvoidance->DrawDebug();
    };
};

#endif // COLLISIONAVOIDANCE_DEMO_H