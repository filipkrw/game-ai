#ifndef FOLLOW_PATH_H
#define FOLLOW_PATH_H

#include "../seek/Seek.h"
#include "Path.h"

enum Algorithm
{
    VANILLA,
    PREDICTIVE,
    SIMPLE
};

class FollowPath : public Seek
{
public:
    FollowPath(Entity *character, Path *path, Algorithm algorithm = VANILLA)
        : Seek(character, 1400.f), path(path), algorithm(algorithm){};

    Path *path;
    Algorithm algorithm;

    // Common
    int currentParam = 0;

    // Predictive
    double predictTime = 0.1f;

    // Simple
    double reachedRadius = 50.f;

    SteeringOutput GetSteering();

private:
    SteeringOutput FollowPathVanilla();
    SteeringOutput FollowPathPredictive();
    SteeringOutput FollowPathSimple();
};

#endif // FOLLOW_PATH_H
