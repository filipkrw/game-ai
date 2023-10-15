#include "InputManager.h"
#include "../core/renderer/Renderer.h"

void InputManager::Update()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    if (leftMouse.isPressed)
    {
        leftMouse.position = Vector2(sf::Mouse::getPosition(*window).x,
                                     sf::Mouse::getPosition(*window).y);
    }
}

void InputManager::ProcessEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        leftMouse.isPressed = true;
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        leftMouse.isPressed = false;
    }
}

void InputManager::Clear()
{
}