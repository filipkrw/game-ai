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
        Vehicle *vehicle1 = new Vehicle(
            gameWorld,                                            // world
            Vector2(650, 450),                                    // position
            0,                                                    // rotation
            Vector2(10, 0),                                       // velocity
            Params::VehicleMass,                                  // mass
            Params::MaxSpeed,                                     // maxSpeed
            Params::MaxSteeringForce,                             // maxForce
            Params::MaxTurnRatePerSecond,                         // maxTurnRate
            Vector2(Params::VehicleScale, Params::VehicleScale)); // scale

        vehicle1->Steering()->ArriveOn();

        vehicles.push_back(vehicle1);
    };

    void Update(double dt)
    {
        Demo::Update(dt);

        for (auto vehicle : vehicles)
        {
            vehicle->Update(dt);
        }
    }

    void Render()
    {
        Demo::Render();

        for (auto vehicle : vehicles)
        {
            vehicle->Render();
        }
    };
};

#endif // ARRIVE_DEMO_H