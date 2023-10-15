#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "../../core/renderer/Renderer.h"
#include "../../util/Vector2.h"

class Crosshair
{
public:
    Vector2 position;

public:
    Crosshair()
    {
        position = Vector2(100, 100);
    }

    Crosshair(Vector2 position)
    {
        this->position = position;
    }

    void Render()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        sf::RectangleShape horizontal(sf::Vector2f(20, 1));
        horizontal.setPosition(position.X() - 10.f, position.Y());
        horizontal.setFillColor(sf::Color::White);
        window->draw(horizontal);

        sf::RectangleShape vertical(sf::Vector2f(1, 20));
        vertical.setPosition(position.X(), position.Y() - 10.f);
        vertical.setFillColor(sf::Color::White);
        window->draw(vertical);
    }
};

#endif // CROSSHAIR_H
