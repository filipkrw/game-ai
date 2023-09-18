#include "KinematicArrive.h"

void KinematicArrive::CalculateSteering(Vector2 target)
{
    Vector2 direction = target - character->position;
    double distance = direction.Length();

    if (distance < targetRadius)
    {
        steering.velocity = Vector2(0, 0);
        return;
    }

    double targetSpeed;

    if (distance > slowRadius)
    {
        targetSpeed = maxSpeed;
    }
    else
    {
        targetSpeed = maxSpeed * distance / slowRadius;
    }

    Vector2 targetVelocity = direction;
    targetVelocity.Normalize();
    targetVelocity *= targetSpeed;

    steering.velocity = targetVelocity - character->velocity;
    steering.velocity /= timeToTarget;

    steering.velocity.Truncate(maxAcceleration);

    steering.rotation = 0;
}

void KinematicArrive::DrawDebug()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
        sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

    window->draw(line, 2, sf::Lines);
}