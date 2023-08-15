#ifndef SEEK_DEMO_H
#define SEEK_DEMO_H

#include "Demo.h"
#include "../Vehicle.h"
#include "../params/Params.h"
#include "../util/Util.h"

class SeekDemo : public Demo
{
private:
    std::vector<Vehicle *> vehicles;

public:
    SeekDemo() : Demo()
    {
        // VehicleParams params;
        // params.initialPosition = Vector2(400, 400);
        // params.maxSpeed = 10000;
        // params.maxForce = 30000;
        // Vehicle *vehicle = new Vehicle(gameWorld, params);
        // vehicle->Steering()->SeekOn();
        // vehicles.push_back(vehicle);

        // VehicleParams params2;
        // params2.initialPosition = Vector2(100, 100);
        // params2.maxSpeed = 8000;
        // params2.maxForce = 26000;
        // Vehicle *vehicle2 = new Vehicle(gameWorld, params2);
        // vehicle2->Steering()->SeekOn();
        // vehicles.push_back(vehicle2);

        // VehicleParams params3;
        // params3.initialPosition = Vector2(200, 200);
        // params3.maxSpeed = 12000;
        // params3.maxForce = 22000;
        // Vehicle *vehicle3 = new Vehicle(gameWorld, params3);
        // vehicle3->Steering()->SeekOn();
        // vehicles.push_back(vehicle3);

        for (int i = 0; i < 2; i++)
        {
            VehicleParams params;
            params.initialPosition = Vector2(450, 300);
            params.maxSpeed = Util::RandomBetween(8000, 12000);
            params.maxForce = Util::RandomBetween(20000, 25000);
            params.color = sf::Color(Util::RandomBetween(50, 200), Util::RandomBetween(50, 200), Util::RandomBetween(50, 200));
            Vehicle *vehicle = new Vehicle(gameWorld, params);
            vehicle->Steering()->SeekOn();
            vehicles.push_back(vehicle);
        }
    };

    void Update(double dt)
    {
        for (auto vehicle : vehicles)
        {
            vehicle->Update(dt);
        }
    }

    void Render()
    {
        for (auto vehicle : vehicles)
        {
            vehicle->Render();
        }
    };
};

#endif // SEEK_DEMO_H