#include "Entity.h"
#include "SteeringOutput.h"
#include "../../util/Vector2.h"
#include "../../core/renderer/Renderer.h"

void Entity::Update(SteeringOutput steering, double dt)
{
    velocity += steering.velocity * dt;

    if (velocity.Length() > maxSpeed)
    {
        velocity.Normalize();
        velocity *= maxSpeed;
    }

    position += velocity * dt;

    rotation += steering.rotation * dt;
    orientation += rotation * dt;
}

double Entity::NewOrientation(double currentOrientation, Vector2 velocity)
{
    if (velocity.LengthSq() > 0)
    {
        return atan2(-velocity.x, velocity.y);
    }

    return currentOrientation;
}

void Entity::Render()
{
    Vector2 heading = Vector2::FromAngle(orientation);
    Vector2 side = heading.Perp();

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(position.x + heading.x * 20, position.y + heading.y * 20));
    triangle.setPoint(1, sf::Vector2f(position.x + side.x * 10, position.y + side.y * 10));
    triangle.setPoint(2, sf::Vector2f(position.x - side.x * 10, position.y - side.y * 10));
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(color);
    triangle.setOutlineThickness(1.f);

    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    window->draw(triangle);
}

void Entity::DrawDebug()
{

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(position.x, position.y), sf::Color::Red),
        sf::Vertex(sf::Vector2f(position.x + velocity.x, position.y + velocity.y), sf::Color::Red)};

    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    window->draw(line, 2, sf::Lines);
}