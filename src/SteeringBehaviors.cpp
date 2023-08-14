#include <cmath>

#include "SteeringBehaviors.h"
#include "util/Vector2.h"
#include "Vehicle.h"
#include "GameWorld.h"
#include "params/Params.h"
#include "renderer/Renderer.h"

SteeringBehaviors::SteeringBehaviors(Vehicle *vehicle) : m_pVehicle(vehicle),
                                                         m_iFlags(0),
                                                         //  m_dDBoxLength(Prm.MinDetectionBoxLength),
                                                         //  m_dWeightSeparation(Params::SeparationWeight),
                                                         //  m_dWeightCohesion(Params::CohesionWeight),
                                                         //  m_dWeightAlignment(Params::AlignmentWeight),
                                                         m_dWeightWander(Params::WanderWeight),
                                                         //  m_dWeightObstacleAvoidance(Params::ObstacleAvoidanceWeight),
                                                         //  m_dWeightWallAvoidance(Params::WallAvoidanceWeight),
                                                         //  m_dViewDistance(Params::ViewDistance),
                                                         //  m_dWallDetectionFeelerLength(Params::WallDetectionFeelerLength),
                                                         //  m_Feelers(3),
                                                         //  m_Deceleration(normal),
                                                         m_pTargetAgent1(NULL),
                                                         m_pTargetAgent2(NULL),
                                                         m_dWanderDistance(Params::WanderDist),
                                                         m_dWanderJitter(Params::WanderJitterPerSec),
                                                         m_dWanderRadius(Params::WanderRad),
                                                         //  m_dWaypointSeekDistSq(WaypointSeekDist * WaypointSeekDist),
                                                         //  m_dWeightSeek(Params::SeekWeight),
                                                         //  m_dWeightFlee(Params::FleeWeight),
                                                         m_dWeightArrive(Params::ArriveWeight),
                                                         m_dWeightPursuit(Params::PursuitWeight),
                                                         //  m_dWeightOffsetPursuit(Params::OffsetPursuitWeight),
                                                         //  m_dWeightInterpose(Params::InterposeWeight),
                                                         //  m_dWeightHide(Params::HideWeight),
                                                         m_dWeightEvade(Params::EvadeWeight),
                                                         //  m_dWeightFollowPath(Params::FollowPathWeight),
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

    // lookAheadTime += TurnAroundTime(m_pVehicle, evader->Pos());

    m_vPursuitTarget = evader->Pos() + evader->Velocity() * lookAheadTime;

    return Seek(evader->Pos() + evader->Velocity() * lookAheadTime);
}

Vector2 SteeringBehaviors::Evade(Vehicle *pursuer)
{
    Vector2 toPursuer = pursuer->Pos() - m_pVehicle->Pos();

    double lookAheadTime = toPursuer.Length() / (m_pVehicle->MaxSpeed() + pursuer->Speed());

    return Flee(pursuer->Pos() + pursuer->Velocity() * lookAheadTime, 0.f);
}

// Page 97
Vector2 SteeringBehaviors::Wander()
{
    m_vWanderTarget += Vector2(
        Util::RandomBetween(-1, 1) * m_dWanderJitter,
        Util::RandomBetween(-1, 1) * m_dWanderJitter);

    m_vWanderTarget = Vector2::Normalize(m_vWanderTarget) * m_dWanderRadius;

    Vector2 targetLocal = m_vWanderTarget + Vector2(m_dWanderDistance, 0);

    Vector2 targetWorld = Util::PointToWorldSpace(
        targetLocal,
        m_pVehicle->Heading(),
        m_pVehicle->Side(),
        m_pVehicle->Pos());

    return targetWorld - m_pVehicle->Pos();
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

    if (On(evade))
    {
        m_vSteeringForce += Evade(m_pTargetAgent1) * m_dWeightEvade;
    }

    if (On(wander))
    {
        m_vSteeringForce += Wander() * m_dWeightWander;
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

// Page 95 in the book; not sure how it's supposed to work, it doesn't even
// take vehicle turning rate into account
double TurnAroundTime(Vehicle *vehicle, Vector2 targetPosition)
{
    Vector2 toTarget = Vector2::Normalize(targetPosition - vehicle->Pos());

    double dot = vehicle->Heading().Dot(toTarget);

    const double coefficient = 0.3;

    return (dot - 1.0) * -coefficient;
}