#ifndef FOLLOW_PATH_H
#define FOLLOW_PATH_H

#include "../seek/Seek.h"
#include "Path.h"

enum Algorithm
{
    VANILLA,
    PREDICTIVE,
};

class FollowPath : public Seek
{
public:
    FollowPath(Entity *character, Path *path)
        : Seek(character, 1400.f), path(path){};

    Path *path;
    Algorithm algorithm = VANILLA;

    // Common
    int currentParam = 0;

    // Predictive
    double predictTime = 0.1f;

    SteeringOutput GetSteering();

private:
    SteeringOutput FollowPathVanilla();
    SteeringOutput FollowPathPredictive();
};

#endif // FOLLOW_PATH_H
