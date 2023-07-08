#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include <SFML/System/Vector2.hpp>
#include "BaseGameEntity.h"
#include "util/Vector2.h"

class MovingEntity : public BaseGameEntity
{
protected:
    Vector2 m_vVelocity;
    Vector2 m_vHeading;
    Vector2 m_vSide;

    double m_dMass;
    double m_dMaxSpeed;
    double m_dMaxForce;
    double m_dMaxTurnRate;

public:
    MovingEntity(int id) : BaseGameEntity(id) {}

    double Velocity() { return m_vVelocity.Length(); }
    double MaxSpeed() { return m_dMaxSpeed; }
};

#endif // MOVINGENTITY_H