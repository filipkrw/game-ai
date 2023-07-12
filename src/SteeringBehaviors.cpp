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

Vector2 SteeringBehaviors::Flee(Vector2 targetPos)
{
    const double panicDistanceSq = 100.0f * 100.0f;
    if (m_pVehicle->Pos().DistanceSq(targetPos) > panicDistanceSq)
    {
        return Vector2(0, 0);
    }
    Vector2 desiredVelocity = Vector2::Normalize(m_pVehicle->Pos() - targetPos) * m_pVehicle->MaxSpeed();
    return desiredVelocity - m_pVehicle->Velocity();
}