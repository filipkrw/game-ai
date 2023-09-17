#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <SFML/Graphics.hpp>
#include "../../util/Vector2.h"
#include "KinematicSteeringOutput.h"

class KinematicEntity
{
public:
    Vector2 position;
    double orientation;

    Vector2 velocity;
    double rotation;

    double maxSpeed;

public:
    KinematicEntity(Vector2 position, double maxSpeed = 100.0f);

    void Update(KinematicSteeringOutput steering, double dt);
    double NewOrientation(double currentOrientation, Vector2 velocity);

    void Render();
    void DrawDebug();
};

#endif // KINEMATIC_H
