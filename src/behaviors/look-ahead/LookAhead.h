#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include "../align/Align.h"

class LookAhead : public Align
{
public:
    LookAhead(Entity *character) : Align(character){};

    SteeringOutput GetSteering();
};

#endif // LOOKAHEAD_H
