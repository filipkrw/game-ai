#include "KinematicFace.h"

void KinematicFace::CalculateSteering(Vector2 position)
{
    Vector2 direction = position - character->position;

    if (direction.Length() == 0)
    {
        return;
    }

    double targetOrientation = Vector2::ToAngle(direction);

    return KinematicAlign::CalculateSteering(targetOrientation);
}