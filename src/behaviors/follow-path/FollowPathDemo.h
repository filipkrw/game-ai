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
        entity = new Entity(Vector2(100, 100), 150.0f);

        path = new Path();

        for (int i = 0; i < 5; i++)
        {
            path->AddWaypoint(Vector2(750, 100));
            path->AddWaypoint(Vector2(400, 100));
            path->AddWaypoint(Vector2(200, 300));
            path->AddWaypoint(Vector2(100, 550));
            path->AddWaypoint(Vector2(760, 500));
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