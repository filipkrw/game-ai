#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "crosshair/Crosshair.h"
#include "params/Params.h"

GameWorld::GameWorld()
{
    m_pCrosshair = new Crosshair();
}

void GameWorld::Update(double dt)
{
    inputManager.Update();

    if (inputManager.GetLeftMouse().isPressed)
    {
        m_pCrosshair->SetPosition(inputManager.GetLeftMouse().position);
    }
}

void GameWorld::Render()
{
    m_pCrosshair->Render();
}