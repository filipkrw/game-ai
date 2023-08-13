#ifndef STEERING_BEHAVIORS_H
#define STEERING_BEHAVIORS_H

#include "util/Vector2.h"

class Vehicle;

enum Deceleration
{
    slow = 3,
    normal = 2,
    fast = 1
};

class SteeringBehaviors
{
public:
    enum summing_method
    {
        weighted_average,
        prioritized,
        dithered
    };

private:
    enum behavior_type
    {
        none = 0x00000,
        seek = 0x00002,
        flee = 0x00004,
        arrive = 0x00008,
        wander = 0x00010,
        cohesion = 0x00020,
        separation = 0x00040,
        allignment = 0x00080,
        obstacle_avoidance = 0x00100,
        wall_avoidance = 0x00200,
        follow_path = 0x00400,
        pursuit = 0x00800,
        evade = 0x01000,
        interpose = 0x02000,
        hide = 0x04000,
        flock = 0x08000,
        offset_pursuit = 0x10000,
    };

    Vehicle *m_pVehicle;

    Vector2 m_vSteeringForce;

    int m_iFlags = 0;
    Vehicle *m_pTargetAgent1 = nullptr;
    Vehicle *m_pTargetAgent2 = nullptr;
    Vector2 m_vOffset = Vector2(0, 0);

    double m_dWeightSeparation;
    double m_dWeightCohesion;
    double m_dWeightAlignment;
    double m_dWeightWander;
    double m_dWeightObstacleAvoidance;
    double m_dWeightWallAvoidance;
    double m_dWeightSeek;
    double m_dWeightFlee;
    double m_dWeightArrive;
    double m_dWeightPursuit;
    double m_dWeightOffsetPursuit;
    double m_dWeightInterpose;
    double m_dWeightHide;
    double m_dWeightEvade;
    double m_dWeightFollowPath;

    summing_method m_SummingMethod;

public:
    SteeringBehaviors(Vehicle *vehicle);

    Vector2 Calculate();

    Vector2 CalculateWeightedSum();

    bool On(behavior_type bt)
    {
        return (m_iFlags & bt) == bt;
    }

    Vector2 Seek(Vector2 targetPos);
    Vector2 Flee(Vector2 targetPos, double panicDistance = -1.0f);
    Vector2 Arrive(Vector2 targetPos, Deceleration deceleration = normal);
    Vector2 Pursuit(Vehicle *evader);

    void FleeOn() { m_iFlags |= flee; }
    void SeekOn() { m_iFlags |= seek; }
    void ArriveOn() { m_iFlags |= arrive; }
    void WanderOn() { m_iFlags |= wander; }
    void PursuitOn(Vehicle *v)
    {
        m_iFlags |= pursuit;
        m_pTargetAgent1 = v;
    }
    void EvadeOn(Vehicle *v)
    {
        m_iFlags |= evade;
        m_pTargetAgent1 = v;
    }
    void CohesionOn() { m_iFlags |= cohesion; }
    void SeparationOn() { m_iFlags |= separation; }
    void AlignmentOn() { m_iFlags |= allignment; }
    void ObstacleAvoidanceOn() { m_iFlags |= obstacle_avoidance; }
    void WallAvoidanceOn() { m_iFlags |= wall_avoidance; }
    void FollowPathOn() { m_iFlags |= follow_path; }
    void InterposeOn(Vehicle *v1, Vehicle *v2)
    {
        m_iFlags |= interpose;
        m_pTargetAgent1 = v1;
        m_pTargetAgent2 = v2;
    }
    void HideOn(Vehicle *v)
    {
        m_iFlags |= hide;
        m_pTargetAgent1 = v;
    }
    void OffsetPursuitOn(Vehicle *v1, const Vector2 offset)
    {
        m_iFlags |= offset_pursuit;
        m_vOffset = offset;
        m_pTargetAgent1 = v1;
    }
    void FlockingOn()
    {
        CohesionOn();
        AlignmentOn();
        SeparationOn();
        WanderOn();
    }

    void FleeOff()
    {
        if (On(flee))
            m_iFlags ^= flee;
    }
    void SeekOff()
    {
        if (On(seek))
            m_iFlags ^= seek;
    }
    void ArriveOff()
    {
        if (On(arrive))
            m_iFlags ^= arrive;
    }
    void WanderOff()
    {
        if (On(wander))
            m_iFlags ^= wander;
    }
    void PursuitOff()
    {
        if (On(pursuit))
            m_iFlags ^= pursuit;
    }
    void EvadeOff()
    {
        if (On(evade))
            m_iFlags ^= evade;
    }
    void CohesionOff()
    {
        if (On(cohesion))
            m_iFlags ^= cohesion;
    }
    void SeparationOff()
    {
        if (On(separation))
            m_iFlags ^= separation;
    }
    void AlignmentOff()
    {
        if (On(allignment))
            m_iFlags ^= allignment;
    }
    void ObstacleAvoidanceOff()
    {
        if (On(obstacle_avoidance))
            m_iFlags ^= obstacle_avoidance;
    }
    void WallAvoidanceOff()
    {
        if (On(wall_avoidance))
            m_iFlags ^= wall_avoidance;
    }
    void FollowPathOff()
    {
        if (On(follow_path))
            m_iFlags ^= follow_path;
    }
    void InterposeOff()
    {
        if (On(interpose))
            m_iFlags ^= interpose;
    }
    void HideOff()
    {
        if (On(hide))
            m_iFlags ^= hide;
    }
    void OffsetPursuitOff()
    {
        if (On(offset_pursuit))
            m_iFlags ^= offset_pursuit;
    }
    void FlockingOff()
    {
        CohesionOff();
        AlignmentOff();
        SeparationOff();
        WanderOff();
    }

    bool isFleeOn() { return On(flee); }
    bool isSeekOn() { return On(seek); }
    bool isArriveOn() { return On(arrive); }
    bool isWanderOn() { return On(wander); }
    bool isPursuitOn() { return On(pursuit); }
    bool isEvadeOn() { return On(evade); }
    bool isCohesionOn() { return On(cohesion); }
    bool isSeparationOn() { return On(separation); }
    bool isAlignmentOn() { return On(allignment); }
    bool isObstacleAvoidanceOn() { return On(obstacle_avoidance); }
    bool isWallAvoidanceOn() { return On(wall_avoidance); }
    bool isFollowPathOn() { return On(follow_path); }
    bool isInterposeOn() { return On(interpose); }
    bool isHideOn() { return On(hide); }
    bool isOffsetPursuitOn() { return On(offset_pursuit); }

    double TurnAroundTime(Vehicle *vehicle, Vector2 targetPosition);

    // Test properites
    Vector2 m_vPursuitTarget;
};

#endif // STEERING_BEHAVIORS_H