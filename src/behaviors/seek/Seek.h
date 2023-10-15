#ifndef SEEK_H
#define SEEK_H

#include "../common/Entity.h"
#include "../common/SteeringOutput.h"

class Seek
{
public:
    Seek(Entity *character, float maxSpeed = 1000.f)
        : character(character), maxSpeed(maxSpeed) {}

    Entity *character;
    float maxSpeed;
    SteeringOutput steering;

    void CalculateSteering(Vector2 target);
    void DrawDebug();
};

#endif // SEEK_H