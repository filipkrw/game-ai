#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "crosshair/Crosshair.h"

GameWorld::GameWorld()
{
    m_pCrosshair = new Crosshair();

    m_Vehicles = std::vector<Vehicle *>();

    Vehicle *vehicle1 = new Vehicle(
        this,
        Vector2(650, 450),
        0,
        Vector2(-1050, 0), // velocity
        0.1,               // mass
        200,               // maxSpeed
        1000,              // maxForce
        10,
        Vector2(1, 1));

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

    vehicle2->Steering()->EvadeOn(vehicle1);
    vehicle2->Steering()->WanderOn();
    m_Vehicles.push_back(vehicle2);
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
}