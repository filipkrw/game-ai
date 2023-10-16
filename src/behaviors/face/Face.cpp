#include "Face.h"

SteeringOutput Face::GetSteering(Vector2 position)
{
    Vector2 direction = position - character->position;

    if (direction.Length() == 0)
    {
        return SteeringOutput();
    }

    double targetOrientation = Vector2::ToAngle(direction);

    return Align::GetSteering(targetOrientation);
}