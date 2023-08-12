#include <cmath>

#include "SteeringBehaviors.h"
#include "util/Vector2.h"
#include "Vehicle.h"
#include "GameWorld.h"
#include "params/Params.h"

SteeringBehaviors::SteeringBehaviors(Vehicle *vehicle) : m_pVehicle(vehicle),
                                                         m_iFlags(0),
                                                         //  m_dDBoxLength(Prm.MinDetectionBoxLength),
                                                         m_dWeightSeparation(Params::SeparationWeight),
                                                         m_dWeightCohesion(Params::CohesionWeight),
                                                         m_dWeightAlignment(Params::AlignmentWeight),
                                                         m_dWeightObstacleAvoidance(Params::ObstacleAvoidanceWeight),
                                                         m_dWeightWander(Params::WanderWeight),
                                                         m_dWeightWallAvoidance(Params::WallAvoidanceWeight),
                                                         //  m_dViewDistance(Params::ViewDistance),
                                                         //  m_dWallDetectionFeelerLength(Params::WallDetectionFeelerLength),
                                                         //  m_Feelers(3),
                                                         //  m_Deceleration(normal),
                                                         m_pTargetAgent1(NULL),
                                                         m_pTargetAgent2(NULL),
                                                         //  m_dWanderDistance(WanderDist),
                                                         //  m_dWanderJitter(WanderJitterPerSec),
                                                         //  m_dWanderRadius(WanderRad),
                                                         //  m_dWaypointSeekDistSq(WaypointSeekDist * WaypointSeekDist),
                                                         m_dWeightSeek(Params::SeekWeight),
                                                         m_dWeightFlee(Params::FleeWeight),
                                                         m_dWeightArrive(Params::ArriveWeight),
                                                         m_dWeightPursuit(Params::PursuitWeight),
                                                         m_dWeightOffsetPursuit(Params::OffsetPursuitWeight),
                                                         m_dWeightInterpose(Params::InterposeWeight),
                                                         m_dWeightHide(Params::HideWeight),
                                                         m_dWeightEvade(Params::EvadeWeight),
                                                         m_dWeightFollowPath(Params::FollowPathWeight),
                                                         //  m_bCellSpaceOn(false),
                                                         m_SummingMethod(weighted_average)
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

Vector2 SteeringBehaviors::CalculateWeightedSum()
{
    Vector2 crosshairPosition = m_pVehicle->World()->GetCrosshair()->Pos();

    if (On(flee))
    {
        double m_dPanicDistance = 200.0f;
        m_vSteeringForce += Flee(crosshairPosition, m_dPanicDistance) * m_dWeightFlee;
    }

    if (On(arrive))
    {
        Deceleration m_Deceleration = normal;
        m_vSteeringForce += Arrive(crosshairPosition, m_Deceleration) * m_dWeightArrive;
    }

    if (On(pursuit))
    {
        m_vSteeringForce += Pursuit(m_pTargetAgent1) * m_dWeightPursuit;
    }

    m_vSteeringForce.Truncate(m_pVehicle->MaxForce());

    return m_vSteeringForce;
}

Vector2 SteeringBehaviors::Calculate()
{
    m_vSteeringForce.Zero();

    switch (m_SummingMethod)
    {
    case weighted_average:
        m_vSteeringForce = CalculateWeightedSum();
        break;

    case prioritized:
        // m_vSteeringForce = CalculatePrioritized();
        break;

    case dithered:
        // m_vSteeringForce = CalculateDithered();
        break;
    }

    return m_vSteeringForce;
}