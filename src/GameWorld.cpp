#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"

GameWorld::GameWorld()
{
    m_Vehicles = std::vector<Vehicle *>();

    Vehicle v = Vehicle(
        this,
        Vector2(0, 0),
        0,
        Vector2(0, 0),
        1,
        1,
        1,
        1,
        Vector2(1, 1));

    m_Vehicles.push_back(&v);
}

void GameWorld::Update(double dt)
{
    for (int i = 0; i < m_Vehicles.size(); i++)
    {
        m_Vehicles[i]->Update(dt);
    }
}

void GameWorld::Render()
{
}