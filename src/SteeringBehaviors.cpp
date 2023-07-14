#include <cmath>

#include "SteeringBehaviors.h"
#include "util/Vector2.h"
#include "Vehicle.h"

SteeringBehaviors::SteeringBehaviors(Vehicle *vehicle)
{
    m_pVehicle = vehicle;
}

Vector2 SteeringBehaviors::Seek(Vector2 targetPos)
{
    Vector2 desiredVelocity = Vector2::Normalize(targetPos - m_pVehicle->Pos()) * m_pVehicle->MaxSpeed();
    return desiredVelocity - m_pVehicle->Velocity();
}

Vector2 SteeringBehaviors::Flee(Vector2 targetPos, double panicDistance)
{
    if (panicDistance > 0.0f)
    {
        const double panicDistanceSq = std::pow(panicDistance, 2);
        if (m_pVehicle->Pos().DistanceSq(targetPos) > panicDistanceSq)
        {
            return Vector2(0, 0);
        }
    }
    Vector2 desiredVelocity = Vector2::Normalize(m_pVehicle->Pos() - targetPos) * m_pVehicle->MaxSpeed();
    return desiredVelocity - m_pVehicle->Velocity();
}

Vector2 SteeringBehaviors::Arrive(Vector2 targetPos, Deceleration deceleration)
{
    Vector2 toTarget = targetPos - m_pVehicle->Pos();
    double distance = toTarget.Length();

    if (distance > 0)
    {
        const double decelerationTweaker = 0.3;
        double speed = distance / ((double)deceleration * decelerationTweaker);
        speed = std::min(speed, m_pVehicle->MaxSpeed());

        Vector2 desiredVelocity = toTarget * speed / distance;
        return desiredVelocity - m_pVehicle->Velocity();
    }

    return Vector2(0, 0);
}

Vector2 SteeringBehaviors::Pursuit(Vehicle *evader)
{
    Vector2 toEvader = evader->Pos() - m_pVehicle->Pos();
    double relativeHeading = m_pVehicle->Heading().Dot(evader->Heading());

    if (toEvader.Dot(m_pVehicle->Heading()) > 0 && relativeHeading < -0.95)
    {
        return Seek(evader->Pos());
    }

    double lookAheadTime = toEvader.Length() / (m_pVehicle->MaxSpeed() + evader->Speed());
    return Seek(evader->Pos() + evader->Velocity() * lookAheadTime);
}

Vector2 SteeringBehaviors::Calculate()
{
    return Vector2();
}