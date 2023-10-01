#ifndef KINEMATIC_ARRIVE_DEMO_H
#define KINEMATIC_ARRIVE_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "KinematicArrive.h"
#include "../look-ahead/LookAhead.h"

class KinematicArriveDemo : public Demo
{
private:
    KinematicEntity *entity;
    KinematicArrive *arrive;
    LookAhead *lookAhead;

public:
    KinematicArriveDemo() : Demo()
    {
        entity = new KinematicEntity(Vector2(600, 500));
        arrive = new KinematicArrive(entity);

        KinematicAlignParams *lookAheadParams = new KinematicAlignParams{
            .maxAngularAcceleration = 1000,
            .maxRotation = 7.5,
            .targetRadius = 0.02,
            .slowRadius = 0.8,
            .timeToTarget = 0.01,
        };

        lookAhead = new LookAhead(entity, lookAheadParams);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->GetCrosshair()->Position();
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

#endif // KINEMATIC_ARRIVE_DEMO_H