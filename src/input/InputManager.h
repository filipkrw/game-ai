#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../util/Vector2.h"

typedef struct
{
    bool isPressed;
    Vector2 position;
} MouseEvent;

class InputManager
{
private:
    MouseEvent leftMouse;

public:
    InputManager(){};

    MouseEvent GetLeftMouse() { return leftMouse; }

    void ProcessEvent(sf::Event event);

    void Clear();
};

#endif // INPUT_MANAGER_H