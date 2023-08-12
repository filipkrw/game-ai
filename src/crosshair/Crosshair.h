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

    void Update(double dt)
    {
        m_vPosition = Vector2(
            sf::Mouse::getPosition(*Renderer::getInstance()->GetWindow()).x,
            sf::Mouse::getPosition(*Renderer::getInstance()->GetWindow()).y);
    }

    void Render()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        sf::RectangleShape horizontal(sf::Vector2f(20, 2));
        horizontal.setPosition(m_vPosition.X() - 10, m_vPosition.Y());
        horizontal.setFillColor(sf::Color::White);
        window->draw(horizontal);

        sf::RectangleShape vertical(sf::Vector2f(2, 20));
        vertical.setPosition(m_vPosition.X(), m_vPosition.Y() - 10);
        vertical.setFillColor(sf::Color::White);
        window->draw(vertical);
    }
};

#endif // CROSSHAIR_H
