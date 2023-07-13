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
        const double decelerationTweaker = 0.1;
        double speed = distance / ((double)deceleration * decelerationTweaker);
        speed = std::min(speed, m_pVehicle->MaxSpeed());

        Vector2 desiredVelocity = toTarget * speed / distance;
        return desiredVelocity - m_pVehicle->Velocity() / 2;
    }

    return Vector2(0, 0);
}