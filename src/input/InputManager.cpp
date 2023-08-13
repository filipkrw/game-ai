#include "InputManager.h"
#include "../renderer/Renderer.h"

void InputManager::ProcessEvent(sf::Event event)
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    if (event.type == sf::Event::MouseButtonPressed)
    {
        leftMouse.position = Vector2(
            sf::Mouse::getPosition(*window).x,
            sf::Mouse::getPosition(*window).y);
        leftMouse.isPressed = true;
    }
}

void InputManager::Clear()
{
    leftMouse.isPressed = false;
}