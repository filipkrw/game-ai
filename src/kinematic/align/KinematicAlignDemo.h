#ifndef KINEMATIC_ALIGN_DEMO_H
#define KINEMATIC_ALIGN_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "KinematicAlign.h"
#include "../arrive/KinematicArrive.h"
#include <iostream>

class KinematicAlignDemo : public Demo
{
private:
    KinematicEntity *arriveEntity;
    KinematicArrive *arrive;

    KinematicEntity *alignEntity;
    KinematicAlign *align;

public:
    KinematicAlignDemo() : Demo()
    {
        arriveEntity = new KinematicEntity(Vector2(600, 500));
        arriveEntity->lockVelocityToOrientation = true;
        arrive = new KinematicArrive(arriveEntity);

        alignEntity = new KinematicEntity(Vector2(450, 300));
        align = new KinematicAlign(alignEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->GetCrosshair()->Position();
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

        // entity->DrawDebug();
        // align->DrawDebug();
    };
};

#endif // KINEMATIC_ALIGN_DEMO_H