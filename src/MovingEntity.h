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
    MovingEntity(Vector2 position, double rotation, Vector2 velocity, double mass, double maxSpeed, double maxForce, double maxTurnRate, Vector2 scale, double boundingRadius)
        : BaseGameEntity(position, scale, rotation, boundingRadius)
    {
        m_vVelocity = velocity;
        m_vHeading = Vector2::Normalize(m_vVelocity);
        m_vSide = m_vHeading.Perp();

        m_dMass = mass;
        m_dMaxSpeed = maxSpeed;
        m_dMaxForce = maxForce;
        m_dMaxTurnRate = maxTurnRate;
        m_dBoundingRadius = boundingRadius;
    }

    MovingEntity() : BaseGameEntity() {}
    virtual void Update(double dt) = 0;

    Vector2 Velocity() const { return m_vVelocity; }
    Vector2 Heading() const { return m_vHeading; }
    Vector2 Side() const { return m_vSide; }

    double Mass() const { return m_dMass; }
    double MaxSpeed() const { return m_dMaxSpeed; }
    double MaxForce() const { return m_dMaxForce; }
    double MaxTurnRate() const { return m_dMaxTurnRate; }
    double BoundingRadius() const { return m_dBoundingRadius; }

    double Speed() { return m_vVelocity.Length(); }
};

#endif // MOVINGENTITY_H