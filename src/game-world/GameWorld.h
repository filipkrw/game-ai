#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "../util/Vector2.h"
#include "crosshair/Crosshair.h"
#include <vector>
#include "../core/input/InputManager.h"

class GameWorld
{
public:
    GameWorld();

    InputManager inputManager = InputManager();
    Crosshair *crosshair;

    void Update(double dt);
    void Render();
};

#endif // GAMEWORLD_H