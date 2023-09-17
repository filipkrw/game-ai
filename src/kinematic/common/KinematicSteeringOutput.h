#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H

#include "../../util/Vector2.h"

class KinematicSteeringOutput
{
public:
    Vector2 velocity;
    float rotation;
};

#endif // STEERINGOUTPUT_H