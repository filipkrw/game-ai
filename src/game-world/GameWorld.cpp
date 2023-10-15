#include <iostream>
#include "GameWorld.h"
#include "crosshair/Crosshair.h"

GameWorld::GameWorld()
{
    crosshair = new Crosshair();
}

void GameWorld::Update(double dt)
{
    inputManager.Update();

    if (inputManager.GetLeftMouse().isPressed)
    {
        crosshair->position = inputManager.GetLeftMouse().position;
    }
}

void GameWorld::Render()
{
    crosshair->Render();
}
