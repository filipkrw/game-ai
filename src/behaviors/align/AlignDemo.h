#ifndef _ALIGN_DEMO_H
#define _ALIGN_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Align.h"
#include "../arrive/Arrive.h"
#include <iostream>

class AlignDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;

    Entity *alignEntity;
    Align *align;

public:
    AlignDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(600, 500));
        arriveEntity->lockVelocityToOrientation = true;
        arrive = new Arrive(arriveEntity);

        alignEntity = new Entity(Vector2(450, 300));
        align = new Align(alignEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;
        arrive->CalculateSteering(crosshairPosition);
        arriveEntity->Update(arrive->steering, dt);

        // std::cout << arriveEntity->orientation << std::endl;
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

#endif // _ALIGN_DEMO_H