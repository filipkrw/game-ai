#ifndef FOLLOWPATH_DEMO_H
#define FOLLOWPATH_DEMO_H

#include "../common/Demo.h"
#include "../../game-world/GameWorld.h"
#include "../common/Entity.h"
#include "FollowPath.h"
#include "../look-ahead/LookAhead.h"
#include "Path.h"
#include "../../util/Util.h"

class FollowPathDemo : public Demo
{
private:
    Entity *entity;
    Path *path;
    FollowPath *followPath;

public:
    FollowPathDemo() : Demo()
    {
        entity = new Entity(Vector2(100, 100), 300.0f);

        path = new Path();

        for (int i = 0; i < 5; i++)
        {
            path->AddWaypoint(Vector2(Util::RandomBetween(0, 800), Util::RandomBetween(0, 500)));
        }

        followPath = new FollowPath(entity, path);
    };

    void Update(double dt)
    {
        SteeringOutput steering = followPath->GetSteering();
        entity->Update(steering, dt);
    }

    void Render()
    {
        path->Render();
        entity->Render();
    };
};

#endif // FOLLOWPATH_DEMO_H