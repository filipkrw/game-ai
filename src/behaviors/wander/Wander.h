#ifndef WANDER_H
#define WANDER_H

#include "../face/Face.h"
#include "../../util/Vector2.h"

class Wander : public Face
{
public:
    Wander(Entity *character) : Face(character){};

    Vector2 target = Vector2();

    double wanderOffset = 150;
    double wanderRadius = 15;
    double wanderRate = 0.15;
    double wanderOrientation = 0;
    double maxAcceleration = 100;

    SteeringOutput GetSteering();
    void DrawDebug();
};

#endif // WANDER_H