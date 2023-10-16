#ifndef ALIGN_DEMO_H
#define ALIGN_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Align.h"
#include "../arrive/Arrive.h"
#include <iostream>
#include "../look-ahead/LookAhead.h"

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
        arrive->CalculateSteering(crosshairPosition);
        arriveEntity->Update(arrive->steering, dt);

        lookAhead->CalculateSteering();
        arriveEntity->Update(lookAhead->steering, dt);

        align->CalculateSteering(arriveEntity->orientation);
        alignEntity->Update(align->steering, dt);
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