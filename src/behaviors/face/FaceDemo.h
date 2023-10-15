#ifndef _FACE_DEMO_H
#define _FACE_DEMO_H

#include "../common/Demo.h"
#include "../../GameWorld.h"
#include "../common/Entity.h"
#include "Face.h"
#include "../arrive/Arrive.h"
#include <iostream>

class FaceDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;

    Entity *faceEntity;
    Face *face;

public:
    FaceDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(600, 500));
        arriveEntity->lockVelocityToOrientation = true;
        arrive = new Arrive(arriveEntity);

        faceEntity = new Entity(Vector2(450, 300));
        face = new Face(faceEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;
        arrive->CalculateSteering(crosshairPosition);
        arriveEntity->Update(arrive->steering, dt);

        // std::cout << arriveEntity->orientation << std::endl;
        face->CalculateSteering(arriveEntity->position);
        faceEntity->Update(face->steering, dt);
    }

    void Render()
    {
        arriveEntity->Render();
        faceEntity->Render();

        // arriveEntity->DrawDebug();
        // arrive->DrawDebug();
    };
};

#endif // _FACE_DEMO_H