#include "Separation.h"
#include "../../util/Vector2.h"

SteeringOutput Separation::GetSteering()
{
    SteeringOutput steering = SteeringOutput();

    for (Entity *target : targets)
    {
        Vector2 direction = character->position - target->position;
        double distance = direction.Length();

        if (distance < threshold)
        {
            double strength = std::min(decayCoefficient / (distance * distance), maxAcceleration);
            direction = Vector2::Normalize(direction);

            steering.velocity += direction * strength;
        }
    }

    return steering;
}