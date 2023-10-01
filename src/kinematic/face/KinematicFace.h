#ifndef KINEMATIC_FACE_H
#define KINEMATIC_FACE_H

#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "../../util/Vector2.h"
#include "../align/KinematicAlign.h"

class KinematicFace : public KinematicAlign
{
public:
    KinematicFace(KinematicEntity *character) : KinematicAlign(character){};

    void CalculateSteering(Vector2 position);

private:
    using KinematicAlign::CalculateSteering; // Hide the CalculateSteering from KinematicAlign
};

#endif // KINEMATIC_FACE_H