#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"

GameWorld::GameWorld()
{
    m_Vehicles = std::vector<Vehicle *>();

    Vehicle *v = new Vehicle(
        this,
        Vector2(150, 150),
        0,
        Vector2(0, 0),
        1,
        300,
        0,
        1,
        Vector2(1, 1));

    m_Vehicles.push_back(v);
}

void GameWorld::Update(double dt)
{
    for (Vehicle *v : m_Vehicles)
    {
        v->Update(dt);
    }
}

void GameWorld::Render()
{
    for (Vehicle *v : m_Vehicles)
    {
        v->Render();
    }
}