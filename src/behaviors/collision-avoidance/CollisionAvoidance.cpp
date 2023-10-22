#include "CollisionAvoidance.h"
#include "../../util/Vector2.h"

SteeringOutput CollisionAvoidance::GetSteering()
{
    SteeringOutput steering = SteeringOutput();

    double shortestTime = std::numeric_limits<double>::infinity();

    Entity *firstTarget = nullptr;

    double firstMinSeparation, firstDistance;
    Vector2 firstRelativePosition, firstRelativeVelocity;

    for (Entity *target : targets)
    {
        Vector2 relativePosition = character->position - target->position;
        Vector2 relativeVelocity = character->velocity - target->velocity;
        double relativeSpeed = relativeVelocity.Length();
        double timeToCollision = Vector2::Dot(relativePosition, relativeVelocity) / (relativeSpeed * relativeSpeed);

        double distance = relativePosition.Length();
        double minSeparation = distance - relativeSpeed * timeToCollision;

        if (minSeparation > 2 * radius)
        {
            continue;
        }

        if (timeToCollision > 0 && timeToCollision < shortestTime)
        {
            shortestTime = timeToCollision;
            firstTarget = target;
            firstMinSeparation = minSeparation;
            firstDistance = distance;
            firstRelativePosition = relativePosition;
            firstRelativeVelocity = relativeVelocity;
        }
    }

    if (firstTarget == nullptr)
    {
        return steering;
    }

    if (firstMinSeparation <= 0 || firstDistance < 2 * radius)
    {
        firstRelativePosition = character->position - firstTarget->position;
    }
    else
    {
        firstRelativePosition += firstRelativeVelocity * shortestTime;
    }

    steering.velocity = Vector2::Normalize(firstRelativePosition) * maxAcceleration;
    // steering.rotation = LookAhead::GetSteering().rotation;

    return steering;
}