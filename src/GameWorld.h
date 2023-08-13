#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Vehicle.h"
#include "BaseGameEntity.h"
#include "util/Vector2.h"
#include "crosshair/Crosshair.h"
#include <vector>
#include "input/InputManager.h"

class GameWorld
{
private:
    // a container of all the moving entities
    std::vector<Vehicle *> m_Vehicles;

    // any obstacles
    std::vector<BaseGameEntity *> m_Obstacles;

    // container containing any walls in the environment
    // std::vector<Wall2D> m_Walls;

    // CellSpacePartition<Vehicle *> *m_pCellSpace;

    // any path we may create for the vehicles to follow
    // Path *m_pPath;

    // set true to pause the motion
    bool m_bPaused;

    // local copy of client window dimensions
    int m_cxClient,
        m_cyClient;
    // the position of the crosshair
    Vector2 m_vCrosshair;

    // keeps track of the average FPS
    double m_dAvFrameTime;

    Crosshair *m_pCrosshair;

    // flags to turn aids and obstacles etc on/off
    bool m_bShowWalls;
    bool m_bShowObstacles;
    bool m_bShowPath;
    bool m_bShowDetectionBox;
    bool m_bShowWanderCircle;
    bool m_bShowFeelers;
    bool m_bShowSteeringForce;
    bool m_bShowFPS;
    bool m_bRenderNeighbors;
    bool m_bViewKeys;
    bool m_bShowCellSpaceInfo;

    // void CreateObstacles();

    // void CreateWalls();

public:
    GameWorld();
    void Update(double dt);
    void Render();

    InputManager inputManager = InputManager();

    Crosshair *const GetCrosshair() const { return m_pCrosshair; }
};

#endif // GAMEWORLD_H