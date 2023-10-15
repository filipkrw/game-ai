#include "Face.h"

void Face::CalculateSteering(Vector2 position)
{
    Vector2 direction = position - character->position;

    if (direction.Length() == 0)
    {
        return;
    }

    double targetOrientation = Vector2::ToAngle(direction);

    return Align::CalculateSteering(targetOrientation);
}