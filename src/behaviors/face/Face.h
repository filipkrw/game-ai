#ifndef FACE_H
#define FACE_H

#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "../../util/Vector2.h"
#include "../align/Align.h"

class Face : public Align
{
public:
    Face(Entity *character) : Align(character){};

    SteeringOutput GetSteering(Vector2 position);

private:
    using Align::GetSteering; // Hide the GetSteering from Align
};

#endif // FACE_H