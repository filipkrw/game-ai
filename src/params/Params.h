#ifndef PARAMS_H
#define PARAMS_H

class Params
{
public:
    // static int NumAgents;
    // static int NumObstacles;
    // static double MinObstacleRadius;
    // static double MaxObstacleRadius;

    // number of horizontal cells used for spatial partitioning
    // static int NumCellsX;
    // number of vertical cells used for spatial partitioning
    // static int NumCellsY;

    // how many samples the smoother will use to average a value
    // static int NumSamplesForSmoothing;

    // used to tweak the combined steering force (simply altering the MaxSteeringForce
    // will NOT work!This tweaker affects all the steering force multipliers
    // too).
    // static double SteeringForceTweaker;

    static double MaxSteeringForce;
    static double MaxSpeed;
    static double VehicleMass;

    static double VehicleScale;
    static double MaxTurnRatePerSecond;

    // static double SeparationWeight;
    // static double AlignmentWeight;
    // static double CohesionWeight;
    // static double ObstacleAvoidanceWeight;
    // static double WallAvoidanceWeight;
    static double WanderWeight;
    // static double SeekWeight;
    // static double FleeWeight;
    static double ArriveWeight;
    static double PursuitWeight;
    // static double OffsetPursuitWeight;
    // static double InterposeWeight;
    // static double HideWeight;
    static double EvadeWeight;
    // static double FollowPathWeight;

    // how close a neighbour must be before an agent perceives it (considers it
    // to be within its neighborhood)
    // static double ViewDistance;

    // used in obstacle avoidance
    // static double MinDetectionBoxLength;

    // used in wall avoidance
    // static double WallDetectionFeelerLength;

    // these are the probabilities that a steering behavior will be used
    // when the prioritized dither calculate method is used
    // static double prWallAvoidance;
    // static double prObstacleAvoidance;
    // static double prSeparation;
    // static double prAlignment;
    // static double prCohesion;
    // static double prWander;
    // static double prSeek;
    // static double prFlee;
    // static double prEvade;
    // static double prHide;
    // static double prArrive;

    // the radius of the constraining circle for the wander behavior
    static double WanderRad;
    // distance the wander circle is projected in front of the agent
    static double WanderDist;
    // the maximum amount of displacement along the circle each frame
    static double WanderJitterPerSec;

    // used in path following
    static double WaypointSeekDist;
};

#endif