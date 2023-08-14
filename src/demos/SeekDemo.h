#ifndef SEEK_DEMO_H
#define SEEK_DEMO_H

#include "Demo.h"
#include "../Vehicle.h"
#include "../params/Params.h"

class SeekDemo : public Demo
{
private:
    std::vector<Vehicle *> vehicles;

public:
    SeekDemo() : Demo()
    {
        VehicleParams vehicle2Params;
        Vehicle *vehicle = new Vehicle(gameWorld, vehicle2Params);
        vehicle->Steering()->SeekOn();

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

#endif // SEEK_DEMO_H