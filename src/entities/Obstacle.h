#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../BaseGameEntity.h"
#include "../renderer/Renderer.h"

class Obstacle : public BaseGameEntity
{
public:
    Obstacle(Vector2 pos, Vector2 scale) : BaseGameEntity(pos, scale, 0.f) {}
    virtual ~Obstacle() {}

    void Update(double dt) {}

    void Render()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
        sf::CircleShape circle(m_vScale.X());
        circle.setOrigin(m_vScale.X(), m_vScale.Y());
        circle.setPosition(m_vPosition.X(), m_vPosition.Y());
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineThickness(1.f);
        circle.setOutlineColor(sf::Color(86, 86, 86));
        window->draw(circle);
    }
};

#endif // OBSTACLE_H
