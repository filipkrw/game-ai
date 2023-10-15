#ifndef _FACE_H
#define _FACE_H

#include "../../GameWorld.h"
#include "../common/Entity.h"
#include "../../util/Vector2.h"
#include "../align/Align.h"

class Face : public Align
{
public:
    Face(Entity *character) : Align(character){};

    void CalculateSteering(Vector2 position);

private:
    using Align::CalculateSteering; // Hide the CalculateSteering from Align
};

#endif // _FACE_H