#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "crosshair/Crosshair.h"
#include "params/Params.h"

GameWorld::GameWorld()
{
    m_pCrosshair = new Crosshair();

    m_Vehicles = std::vector<Vehicle *>();

    Vehicle *vehicle1 = new Vehicle(
        this,                                                 // world
        Vector2(650, 450),                                    // position
        0,                                                    // rotation
        Vector2(-1050, 0),                                    // velocity
        Params::VehicleMass,                                  // mass
        Params::MaxSpeed,                                     // maxSpeed
        Params::MaxSteeringForce,                             // maxForce
        Params::MaxTurnRatePerSecond,                         // maxTurnRate
        Vector2(Params::VehicleScale, Params::VehicleScale)); // scale

    vehicle1->Steering()->ArriveOn();
    m_Vehicles.push_back(vehicle1);

    Vehicle *vehicle2 = new Vehicle(
        this,
        Vector2(300, 300),
        0,
        Vector2(3, 0), // velocity
        0.1,           // mass
        70,            // maxSpeed
        1000,          // maxForce
        10,
        Vector2(1, 1));

    // vehicle2->Steering()->EvadeOn(vehicle1);
    vehicle2->Steering()->WanderOn();
    m_Vehicles.push_back(vehicle2);

    m_Obstacles = std::vector<Obstacle *>();

    Obstacle *obstacle = new Obstacle(Vector2(400, 400), Vector2(25, 25));

    m_Obstacles.push_back(obstacle);
}

void GameWorld::Update(double dt)
{
    inputManager.Update();

    if (inputManager.GetLeftMouse().isPressed)
    {
        m_pCrosshair->SetPosition(inputManager.GetLeftMouse().position);
    }

    for (Vehicle *v : m_Vehicles)
    {
        v->Update(dt);
    }
}

void GameWorld::Render()
{
    m_pCrosshair->Render();

    for (Vehicle *v : m_Vehicles)
    {
        v->Render();
    }

    for (Obstacle *o : m_Obstacles)
    {
        o->Render();
    }
}