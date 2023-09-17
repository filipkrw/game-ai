#ifndef KINEMATIC_SEEK_DEMO_H
#define KINEMATIC_SEEK_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "KinematicSeek.h"

class KinematicSeekDemo : public Demo
{
private:
    KinematicEntity *entity;
    KinematicSeek *seek;

public:
    KinematicSeekDemo() : Demo()
    {
        entity = new KinematicEntity(Vector2(600, 500), 500.0f);
        seek = new KinematicSeek(entity, 1500.0f);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->GetCrosshair()->Position();
        seek->GetSteering(crosshairPosition);
        entity->Update(seek->steering, dt);
    }

    void Render()
    {
        entity->Render();

        // entity->DrawDebug();
        // seek->DrawDebug();
    };
};

#endif // KINEMATIC_SEEK_DEMO_H