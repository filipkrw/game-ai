#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

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
    MovingEntity(int id, Vector2 position, double rotation, Vector2 velocity, double mass, double maxSpeed, double maxForce, double maxTurnRate, Vector2 scale) : BaseGameEntity(id, position, scale, rotation)
    {
        m_vVelocity = velocity;
        m_dMass = mass;
        m_dMaxSpeed = maxSpeed;
        m_dMaxForce = maxForce;
        m_dMaxTurnRate = maxTurnRate;
        m_vHeading = Vector2::Normalize(m_vVelocity);
        m_vSide = m_vHeading.Perp();
    }

    MovingEntity(int id) : BaseGameEntity(id) {}

    double Velocity() { return m_vVelocity.Length(); }
    double MaxSpeed() { return m_dMaxSpeed; }
};

#endif // MOVINGENTITY_H