#ifndef ARRIVE_DEMO_H
#define ARRIVE_DEMO_H

#include "Demo.h"
#include "../Vehicle.h"
#include "../params/Params.h"

class ArriveDemo : public Demo
{
private:
    std::vector<Vehicle *> vehicles;

public:
    ArriveDemo() : Demo()
    {
        VehicleParams vehicle2Params;
        Vehicle *vehicle = new Vehicle(gameWorld, vehicle2Params);
        vehicle->Steering()->ArriveOn();

        vehicles.push_back(vehicle);
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

#endif // ARRIVE_DEMO_H