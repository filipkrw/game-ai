#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "../../core/renderer/Renderer.h"
#include "../../util/Vector2.h"
#include "../../behaviors/common/StaticEntity.h"

class Crosshair : public StaticEntity
{
public:
    Crosshair() : StaticEntity(Vector2(5, 5)){};

    Crosshair(Vector2 position) : StaticEntity(position){};

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
