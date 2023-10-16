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
    double wanderRadius = 10;
    double wanderRate = 0.15;
    double wanderOrientation = 0;
    double maxAcceleration = 100;

    void CalculateSteering();
    void DrawDebug();
};

#endif // WANDER_H