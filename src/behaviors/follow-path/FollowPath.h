#ifndef FOLLOW_PATH_H
#define FOLLOW_PATH_H

#include "../seek/Seek.h"
#include "Path.h"

class FollowPath : public Seek
{
public:
    FollowPath(Entity *character, Path *path) : Seek(character), path(path){};

    Path *path;

    int pathOffset = 0;
    int currentParam = 0;

    SteeringOutput GetSteering();
};

#endif // FOLLOW_PATH_H
