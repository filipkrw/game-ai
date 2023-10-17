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
    Path *path;

    Entity *vanillaEntity;
    FollowPath *vanillaFollowPath;

    Entity *predictiveEntity;
    FollowPath *predictiveFollowPath;

public:
    FollowPathDemo() : Demo()
    {
        vanillaEntity = new Entity(Vector2(100, 100), 450.0f);
        predictiveEntity = new Entity(Vector2(100, 100), 450.0f);

        path = new Path();
        path->AddWaypoint(Vector2(100, 100));
        path->AddWaypoint(Vector2(600, 120));
        path->AddWaypoint(Vector2(700, 230));
        path->AddWaypoint(Vector2(1400, 0));
        path->AddWaypoint(Vector2(900, 800));
        path->AddWaypoint(Vector2(200, 570));

        vanillaFollowPath = new FollowPath(vanillaEntity, path);
        predictiveFollowPath = new FollowPath(predictiveEntity, path);
        predictiveFollowPath->algorithm = PREDICTIVE;
    };

    void Update(double dt)
    {
        vanillaEntity->Update(vanillaFollowPath->GetSteering(), dt);
        predictiveEntity->Update(predictiveFollowPath->GetSteering(), dt);
    }

    void Render()
    {
        path->Render();
        vanillaEntity->Render();
        predictiveEntity->Render();
    };
};

#endif // FOLLOWPATH_DEMO_H