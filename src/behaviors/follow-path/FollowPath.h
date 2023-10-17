#ifndef FOLLOW_PATH_H
#define FOLLOW_PATH_H

#include "../seek/Seek.h"
#include "Path.h"

class FollowPath : public Seek
{
public:
    FollowPath(Entity *character, Path *path) : Seek(character, 300.f), path(path){};

    Path *path;
    int currentParam = 0;

    SteeringOutput GetSteering();
};

#endif // FOLLOW_PATH_H
