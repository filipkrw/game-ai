#include "FollowPath.h"

SteeringOutput FollowPath::GetSteering()
{
    int currentParam = path->GetParam(character->position);
    int targetParam = (currentParam + 1) % path->waypoints.size();

    Vector2 targetPosition = path->GetPosition(targetParam);
    return Seek::GetSteering(targetPosition);
}
