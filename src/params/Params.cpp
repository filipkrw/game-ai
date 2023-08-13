#include "Params.h"
#include <cmath>

int Params::NumAgents = 300;
int Params::NumObstacles = 7;
double Params::MinObstacleRadius = 10;
double Params::MaxObstacleRadius = 30;

int Params::NumCellsX = 7;
// number of vertical cells used for spatial partitioning
int Params::NumCellsY = 7;

// how many samples the smoother will use to average a value
int Params::NumSamplesForSmoothing = 10;

// used to tweak the combined steering force (simply altering the MaxSteeringForce
// will NOT work!This tweaker affects all the steering force multipliers
// too).
double Params::SteeringForceTweaker = 200.0;

double Params::MaxSteeringForce = 2.0;
double Params::MaxSpeed = 150.0;
double Params::VehicleMass = 1.0;

double Params::VehicleScale = 3.0;
double Params::MaxTurnRatePerSecond = 0.5 * M_PI;

double Params::SeparationWeight = 1.0;
double Params::AlignmentWeight = 1.0;
double Params::CohesionWeight = 2.0;
double Params::ObstacleAvoidanceWeight = 10.0;
double Params::WallAvoidanceWeight = 10.0;
double Params::WanderWeight = 0.6;
double Params::SeekWeight = 1.0;
double Params::FleeWeight = 1.0;
double Params::ArriveWeight = 1.0;
double Params::PursuitWeight = 1.0;
double Params::OffsetPursuitWeight = 1.0;
double Params::InterposeWeight = 1.0;
double Params::HideWeight = 1.0;
double Params::EvadeWeight = 0.2;
double Params::FollowPathWeight = 0.05;

// how close a neighbour must be before an agent perceives it (considers it
// to be within its neighborhood)
double Params::ViewDistance = 50.0;

// used in obstacle avoidance
double Params::MinDetectionBoxLength = 40.0;

// used in wall avoidance
double Params::WallDetectionFeelerLength = 40.0;

// these are the probabilities that a steering behavior will be used
// when the prioritized dither calculate method is used
double Params::prWallAvoidance = 0.5;
double Params::prObstacleAvoidance = 0.5;
double Params::prSeparation = 0.2;
double Params::prAlignment = 0.3;
double Params::prCohesion = 0.6;
double Params::prWander = 0.8;
double Params::prSeek = 0.8;
double Params::prFlee = 0.6;
double Params::prEvade = 1.0;
double Params::prHide = 0.8;
double Params::prArrive = 0.5;

// the radius of the constraining circle for the wander behavior
double Params::WanderRad = 10;
// distance the wander circle is projected in front of the agent
double Params::WanderDist = 120;
// the maximum amount of displacement along the circle each frame
double Params::WanderJitterPerSec = 4;

// used in path following
double Params::WaypointSeekDist = 20;