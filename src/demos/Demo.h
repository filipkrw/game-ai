#ifndef DEMO_H
#define DEMO_H

#include "../GameWorld.h"
#include <SFML/Graphics.hpp>

class Demo
{
protected:
    GameWorld *gameWorld;

public:
    Demo() { gameWorld = new GameWorld(); }
    ~Demo() { delete gameWorld; };

    void ProcessEvent(sf::Event event)
    {
        gameWorld->inputManager.ProcessEvent(event);
    };

    void BaseUpdate(double dt) { gameWorld->Update(dt); };
    void BaseRender() { gameWorld->Render(); };
};

#endif // DEMO_H