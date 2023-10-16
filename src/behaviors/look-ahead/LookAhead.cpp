#include "LookAhead.h"

SteeringOutput LookAhead::GetSteering()
{
    Vector2 direction = character->velocity;

    if (direction.Length() == 0)
    {
        return SteeringOutput();
    }

    double targetOrientation = Vector2::ToAngle(direction);

    return Align::GetSteering(targetOrientation);
}