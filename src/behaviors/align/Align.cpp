#include "Align.h"

double mapToRange(double rotation)
{
    rotation = fmod(rotation + M_PI, 2 * M_PI);
    if (rotation < 0)
        rotation += 2 * M_PI;
    return rotation - M_PI;
}

SteeringOutput Align::GetSteering(double targetOrientation)
{
    SteeringOutput steering = SteeringOutput();

    double rotation = targetOrientation - character->orientation;
    rotation = mapToRange(rotation);

    double rotationSize = abs(rotation);

    if (rotationSize < targetRadius)
    {
        steering.rotation = 0;
        return steering;
    }

    double targetRotation;

    if (rotationSize > slowRadius)
    {
        targetRotation = maxRotation;
    }
    else
    {
        targetRotation = maxRotation * rotationSize / slowRadius;
    }

    targetRotation *= rotation / rotationSize;

    steering.rotation = targetRotation - character->rotation;
    steering.rotation /= timeToTarget;

    double angularAcceleration = abs(steering.rotation);

    if (angularAcceleration > maxAngularAcceleration)
    {
        steering.rotation /= angularAcceleration;
        steering.rotation *= maxAngularAcceleration;
    }

    return steering;
}
