#ifndef SEPARATION_DEMO_H
#define SEPARATION_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "Separation.h"
#include "../look-ahead/LookAhead.h"
#include "../arrive/Arrive.h"
#include "../../util/Util.h"

class SeparationDemo : public Demo
{
private:
    Entity *arriveEntity;
    Arrive *arrive;

    std::vector<Entity *> separationEntities;
    std::vector<Separation *> separations;

public:
    SeparationDemo() : Demo()
    {
        arriveEntity = new Entity(Vector2(100, 100), 6000.f, sf::Color::Red);
        arrive = new Arrive(arriveEntity);

        for (int i = 0; i < 100; i++)
        {
            Entity *entity = new Entity(Vector2(Util::RandomBetween(250, 750), Util::RandomBetween(250, 750)));
            separationEntities.push_back(entity);

            Separation *separation = new Separation(entity);

            // for (Entity *target : separationEntities)
            // {
            //     separation->targets.push_back(target);
            // }
            separation->targets.push_back(arriveEntity);

            separations.push_back(separation);
        }
    };

    void Update(double dt)
    {
        Vector2 crosshairPosition = gameWorld->crosshair->position;

        SteeringOutput arriveSteering = arrive->GetSteering(crosshairPosition);
        arriveEntity->Update(arriveSteering, dt);

        for (int i = 0; i < separationEntities.size(); i++)
        {
            Entity *entity = separationEntities[i];
            Separation *separation = separations[i];

            SteeringOutput separationSteering = separation->GetSteering();
            entity->Update(separationSteering, dt);
        }
    }

    void Render()
    {
        arriveEntity->Render();

        for (Entity *entity : separationEntities)
        {
            entity->Render();
        }
    };
};

#endif // SEPARATION_DEMO_H