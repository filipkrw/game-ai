#ifndef FACE_DEMO_H
#define FACE_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Face.h"
#include "../arrive/Arrive.h"
#include <iostream>

class FaceDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;
    LookAhead *lookAhead;

    Entity *faceEntity;
    Face *face;

public:
    FaceDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(600, 500));
        arrive = new Arrive(arriveEntity);
        lookAhead = new LookAhead(arriveEntity);

        faceEntity = new Entity(Vector2(450, 300));
        face = new Face(faceEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;

        SteeringOutput arriveSteering = arrive->GetSteering(crosshairPosition);
        arriveEntity->Update(arriveSteering, dt);

        SteeringOutput lookAheadSteering = lookAhead->GetSteering();
        arriveEntity->Update(lookAheadSteering, dt);

        SteeringOutput faceSteering = face->GetSteering(arriveEntity->position);
        faceEntity->Update(faceSteering, dt);
    }

    void Render()
    {
        arriveEntity->Render();
        faceEntity->Render();

        // arriveEntity->DrawDebug();
        // arrive->DrawDebug();
    };
};

#endif // FACE_DEMO_H