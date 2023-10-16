#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H

#include "../../util/Vector2.h"

class SteeringOutput
{
public:
    Vector2 velocity = Vector2(0, 0);
    float rotation = 0;
};

#endif // STEERINGOUTPUT_H