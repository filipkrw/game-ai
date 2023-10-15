#ifndef ARRIVE_DEMO_H
#define ARRIVE_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Arrive.h"
#include "../look-ahead/LookAhead.h"

class ArriveDemo : public Demo
{
private:
    Entity *entity;
    Arrive *arrive;
    LookAhead *lookAhead;

public:
    ArriveDemo() : Demo()
    {
        entity = new Entity(Vector2(600, 500));
        arrive = new Arrive(entity);
        lookAhead = new LookAhead(entity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;

        arrive->CalculateSteering(crosshairPosition);
        entity->Update(arrive->steering, dt);

        lookAhead->CalculateSteering();
        entity->Update(lookAhead->steering, dt);
    }

    void Render()
    {
        entity->Render();

        // entity->DrawDebug();
        // arrive->DrawDebug();
    };
};

#endif // ARRIVE_DEMO_H