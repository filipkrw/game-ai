#include "Arrive.h"
#include <iostream>

SteeringOutput Arrive::GetSteering(Vector2 target)
{
    SteeringOutput steering = SteeringOutput();

    Vector2 direction = target - character->position;
    double distance = direction.Length();

    if (distance < targetRadius && character->velocity.Length() < 0.01)
    {
        character->velocity = Vector2(0, 0);
        steering.velocity = Vector2(0, 0);
        return steering;
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

    if (steering.velocity.Dot(direction) > 0)
    {
        steering.velocity.Truncate(maxAcceleration);
    }
    else
    {
        steering.velocity.Truncate(maxDeceleration);
    }

    steering.rotation = LookAhead::GetSteering().rotation;

    return steering;
}

void Arrive::DrawDebug()
{
    // sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    // sf::Vertex line[] = {
    //     sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
    //     sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

    // window->draw(line, 2, sf::Lines);
}