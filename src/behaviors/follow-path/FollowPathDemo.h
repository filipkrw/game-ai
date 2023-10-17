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

    Entity *simpleEntity;
    FollowPath *simpleFollowPath;

public:
    FollowPathDemo() : Demo()
    {
        vanillaEntity = new Entity(Vector2(100, 100), 450.0f);
        predictiveEntity = new Entity(Vector2(100, 100), 450.0f, sf::Color::Red);
        simpleEntity = new Entity(Vector2(100, 100), 450.0f, sf::Color::Magenta);

        path = new Path();
        path->AddWaypoint(Vector2(100, 100));
        path->AddWaypoint(Vector2(400, 70));
        path->AddWaypoint(Vector2(600, 200));
        path->AddWaypoint(Vector2(840, 180));
        path->AddWaypoint(Vector2(800, 850));
        path->AddWaypoint(Vector2(200, 770));

        vanillaFollowPath = new FollowPath(vanillaEntity, path);
        predictiveFollowPath = new FollowPath(predictiveEntity, path, PREDICTIVE);
        simpleFollowPath = new FollowPath(simpleEntity, path, SIMPLE);
    };

    void Update(double dt)
    {
        vanillaEntity->Update(vanillaFollowPath->GetSteering(), dt);
        predictiveEntity->Update(predictiveFollowPath->GetSteering(), dt);
        simpleEntity->Update(simpleFollowPath->GetSteering(), dt);
    }

    void Render()
    {
        path->Render();

        vanillaEntity->Render();
        predictiveEntity->Render();
        simpleEntity->Render();
    };
};

#endif // FOLLOWPATH_DEMO_H