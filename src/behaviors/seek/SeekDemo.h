#ifndef _SEEK_DEMO_H
#define _SEEK_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/Entity.h"
#include "Seek.h"

class SeekDemo : public Demo
{
private:
    Entity *entity;
    Seek *seek;

public:
    SeekDemo() : Demo()
    {
        entity = new Entity(Vector2(600, 500), 500.0f);
        seek = new Seek(entity, 1500.0f);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;
        seek->CalculateSteering(crosshairPosition);
        entity->Update(seek->steering, dt);
    }

    void Render()
    {
        entity->Render();

        // entity->DrawDebug();
        // seek->DrawDebug();
    };
};

#endif // _SEEK_DEMO_H