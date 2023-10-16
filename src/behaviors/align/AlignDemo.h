#ifndef ALIGN_DEMO_H
#define ALIGN_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "../arrive/Arrive.h"
#include "../look-ahead/LookAhead.h"
#include "Align.h"
#include <iostream>

class AlignDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;
    LookAhead *lookAhead;

    Entity *alignEntity;
    Align *align;

public:
    AlignDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(600, 500));
        arrive = new Arrive(arriveEntity);
        lookAhead = new LookAhead(arriveEntity);

        alignEntity = new Entity(Vector2(450, 300));
        align = new Align(alignEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;
        SteeringOutput arriveSteering = arrive->GetSteering(crosshairPosition);
        arriveEntity->Update(arriveSteering, dt);

        SteeringOutput lookAheadSteering = lookAhead->GetSteering();
        arriveEntity->Update(lookAheadSteering, dt);

        SteeringOutput alignSteering = align->GetSteering(arriveEntity->orientation);
        alignEntity->Update(alignSteering, dt);
    }

    void Render()
    {
        arriveEntity->Render();
        alignEntity->Render();

        // arriveEntity->DrawDebug();
        // arrive->DrawDebug();
    };
};

#endif // ALIGN_DEMO_H