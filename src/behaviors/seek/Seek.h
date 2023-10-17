#ifndef SEEK_H
#define SEEK_H

#include "../common/Entity.h"
#include "../common/SteeringOutput.h"
#include "../common/Steering.h"
#include "../look-ahead/LookAhead.h"

class Seek : public LookAhead
{
public:
    Seek(Entity *character, double maxAcceleration = 60.f) : LookAhead(character), maxAcceleration(maxAcceleration){};

    double maxAcceleration;

    SteeringOutput GetSteering(Vector2 target);
    void DrawDebug();
};

#endif // SEEK_H