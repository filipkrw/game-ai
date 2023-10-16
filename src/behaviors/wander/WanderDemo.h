#ifndef WANDER_DEMO_H
#define WANDER_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Wander.h"
#include "../look-ahead/LookAhead.h"

class WanderDemo : public Demo
{
private:
    Entity *entity;
    Wander *wander;

public:
    WanderDemo() : Demo()
    {
        entity = new Entity(Vector2(450, 300), 50.f);
        wander = new Wander(entity);
    };

    void Update(double dt)
    {
        SteeringOutput steering = wander->GetSteering();
        entity->Update(steering, dt);
    }

    void Render()
    {
        entity->Render();
        wander->DrawDebug();
    };
};

#endif // WANDER_DEMO_H