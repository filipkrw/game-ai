#ifndef KINEMATICSEEK_H
#define KINEMATICSEEK_H

#include "../common/KinematicEntity.h"
#include "../common/KinematicSteeringOutput.h"

class KinematicSeek
{
public:
    KinematicSeek(KinematicEntity *character, float maxSpeed = 100.f)
        : character(character), maxSpeed(maxSpeed) {}

    KinematicEntity *character;
    float maxSpeed;
    KinematicSteeringOutput steering;

    void GetSteering(Vector2 target);
    void DrawDebug();
};

#endif // KINEMATICSEEK_H