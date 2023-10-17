#include "FollowPath.h"

SteeringOutput FollowPath::GetSteering()
{
    if (algorithm == PREDICTIVE)
    {
        return FollowPathPredictive();
    }
    return FollowPathVanilla();
};

SteeringOutput FollowPath::FollowPathVanilla()
{
    int currentParam = path->GetParam(character->position);
    int targetParam = (currentParam + 1) % path->waypoints.size();

    Vector2 targetPosition = path->GetPosition(targetParam);
    return Seek::GetSteering(targetPosition);
}

SteeringOutput FollowPath::FollowPathPredictive()
{
    Vector2 futurePosition = character->position + character->velocity * predictTime;
    int currentParam = path->GetParam(futurePosition);
    int targetParam = (currentParam + 1) % path->waypoints.size();

    Vector2 targetPosition = path->GetPosition(targetParam);
    return Seek::GetSteering(targetPosition);
}