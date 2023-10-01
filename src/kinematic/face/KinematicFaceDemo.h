#ifndef KINEMATIC_FACE_DEMO_H
#define KINEMATIC_FACE_DEMO_H

#include "../../demos/Demo.h"
#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "KinematicFace.h"
#include "../arrive/KinematicArrive.h"
#include <iostream>

class KinematicFaceDemo : public Demo
{
private:
    KinematicEntity *arriveEntity;
    KinematicArrive *arrive;

    KinematicEntity *faceEntity;
    KinematicFace *face;

public:
    KinematicFaceDemo() : Demo()
    {
        arriveEntity = new KinematicEntity(Vector2(600, 500));
        arriveEntity->lockVelocityToOrientation = true;
        arrive = new KinematicArrive(arriveEntity);

        faceEntity = new KinematicEntity(Vector2(450, 300));
        face = new KinematicFace(faceEntity);
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->GetCrosshair()->Position();
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

#endif // KINEMATIC_FACE_DEMO_H