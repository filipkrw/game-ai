#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "../renderer/Renderer.h"
#include "../BaseGameEntity.h"
#include "../util/Vector2.h"

class Crosshair : public BaseGameEntity
{
public:
    Crosshair() : BaseGameEntity(BaseGameEntity::GetNextValidID())
    {
        m_vPosition = Vector2(100, 100);
    }

    Crosshair(Vector2 position) : BaseGameEntity(BaseGameEntity::GetNextValidID())
    {
        this->m_vPosition = position;
    }

    void SetPosition(Vector2 position)
    {
        this->m_vPosition = position;
    }

    void Update(double dt) {}

    void Render()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        sf::RectangleShape horizontal(sf::Vector2f(20, 1));
        horizontal.setPosition(m_vPosition.X() - 10.f, m_vPosition.Y());
        horizontal.setFillColor(sf::Color::White);
        window->draw(horizontal);

        sf::RectangleShape vertical(sf::Vector2f(1, 20));
        vertical.setPosition(m_vPosition.X(), m_vPosition.Y() - 10.f);
        vertical.setFillColor(sf::Color::White);
        window->draw(vertical);

        // sf::CircleShape circle(10.f);
        // circle.setFillColor(sf::Color::Transparent);
        // circle.setOutlineThickness(2.f);
        // circle.setOutlineColor(sf::Color::White);
        // circle.setPosition(m_vPosition.X() - 10.f, m_vPosition.Y() - 10.f);
        // window->draw(circle);
    }
};

#endif // CROSSHAIR_H
