#include "LookAhead.h"

void LookAhead::CalculateSteering()
{
    Vector2 direction = character->velocity;

    if (direction.Length() == 0)
    {
        return;
    }

    double targetOrientation = Vector2::ToAngle(direction);

    Align::CalculateSteering(targetOrientation);
}