#ifndef KINEMATIC_ARRIVE_DEMO_H
#define KINEMATIC_ARRIVE_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "KinematicArrive.h"

class KinematicArriveDemo : public Demo
{
private:
    KinematicEntity *entity;
    KinematicArrive *arrive;

public:
    KinematicArriveDemo() : Demo()
    {
        entity = new KinematicEntity(Vector2(600, 500));
        arrive = new KinematicArrive(entity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->GetCrosshair()->Position();
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

#endif // KINEMATIC_ARRIVE_DEMO_H