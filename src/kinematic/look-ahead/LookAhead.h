#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include "../../GameWorld.h"
#include "../common/KinematicEntity.h"
#include "../../util/Vector2.h"
#include "../align/KinematicAlign.h"

class LookAhead : public KinematicAlign
{
public:
    LookAhead(KinematicEntity *character) : KinematicAlign(character){};
    LookAhead(KinematicEntity *character, KinematicAlignParams *params) : KinematicAlign(character, params){};

    void CalculateSteering()
    {
        Vector2 direction = character->velocity;

        if (direction.Length() == 0)
        {
            return;
        }

        double targetOrientation = Vector2::ToAngle(direction);

        KinematicAlign::CalculateSteering(targetOrientation);
    }

private:
    using KinematicAlign::CalculateSteering; // Hide the CalculateSteering from KinematicAlign
};

#endif // LOOKAHEAD_H