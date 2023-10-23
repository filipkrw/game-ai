#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "../../util/Vector2.h"

class StaticEntity
{
public:
    Vector2 position;
    double orientation;

    StaticEntity(Vector2 position, double orientation = 0.0f)
    {
        this->position = position;
        this->orientation = orientation;
    };
};

#endif // STATIC_ENTITY_H