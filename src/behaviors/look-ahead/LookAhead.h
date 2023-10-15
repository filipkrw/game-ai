#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include "../align/Align.h"

class LookAhead : public Align
{
public:
    LookAhead(Entity *character) : Align(character){};

    void CalculateSteering();
};

#endif // LOOKAHEAD_H
