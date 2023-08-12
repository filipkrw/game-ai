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
        Vector2(150, 150),
        0,
        Vector2(-1050, 0), // velocity
        0.1,               // mass
        200,               // maxSpeed
        1000,              // maxForce
        10,
        Vector2(1, 1));

    vehicle1->Steering()->ArriveOn();
    m_Vehicles.push_back(vehicle1);

    // Vehicle *vehicle2 = new Vehicle(
    //     this,
    //     Vector2(600, 550),
    //     0,
    //     Vector2(0, 0), // velocity
    //     0.1,           // mass
    //     200,           // maxSpeed
    //     1000,          // maxForce
    //     1,
    //     Vector2(1, 1));

    // vehicle2->Steering()->ArriveOn();
    // m_Vehicles.push_back(vehicle2);
}

void GameWorld::Update(double dt, sf::Event events[])
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Event event;

    for (int i = 0; i < 1; i++)
    {
        event = events[i];

        if (event.type == sf::Event::MouseButtonPressed)
        {
            Vector2 mousePosition = Vector2(
                sf::Mouse::getPosition(*window).x,
                sf::Mouse::getPosition(*window).y);

            m_pCrosshair->SetPosition(mousePosition);
        }
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