#ifndef _ARRIVE_DEMO_H
#define _ARRIVE_DEMO_H

#include "../common/Demo.h"
#include "../../GameWorld.h"
#include "../common/Entity.h"
#include "Arrive.h"

class ArriveDemo : public Demo
{
private:
    Entity *entity;
    Arrive *arrive;

public:
    ArriveDemo() : Demo()
    {
        entity = new Entity(Vector2(600, 500));
        arrive = new Arrive(entity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;
        arrive->CalculateSteering(crosshairPosition);
        entity->Update(arrive->steering, dt);
    }

    void Render()
    {
        entity->Render();

        // entity->DrawDebug();
        // arrive->DrawDebug();
    };
};

#endif // _ARRIVE_DEMO_H