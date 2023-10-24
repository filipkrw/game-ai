#include "CollisionAvoidance.h"
#include "../../util/Vector2.h"
#include "../../core/renderer/Renderer.h"

SteeringOutput CollisionAvoidance::GetSteering()
{
    SteeringOutput steering = SteeringOutput();

    double timeHorizon = 0.3f;

    for (auto *target : targets)
    {
        double timeToCollision = GetTimeToCollision(target);

        if (timeToCollision > timeHorizon || timeToCollision == 0)
        {
            continue;
        }

        Vector2 avoidanceForce = character->position + character->velocity * timeToCollision - target->position - target->velocity * timeToCollision;

        if (avoidanceForce.x != 0 && avoidanceForce.y != 0)
        {
            avoidanceForce /= sqrt(avoidanceForce.Dot(avoidanceForce)); // Normalize
        }

        double magnitude = 0;

        if (timeToCollision >= 0 && timeToCollision <= timeHorizon)
        {
            magnitude = maxAcceleration * (timeHorizon - timeToCollision) / timeHorizon;
        }

        avoidanceForce *= magnitude;

        steering.velocity += avoidanceForce;
    }

    steering.rotation = 0;

    return steering;
}

double CollisionAvoidance::GetTimeToCollision(Entity *target)
{
    double r = 20 + 20;
    Vector2 x = target->position - character->position;
    double c = x.Dot(x) - r * r;

    // Agents are colliding
    if (c < 0)
    {
        return 0;
    }

    Vector2 v = character->velocity - target->velocity;
    double a = v.Dot(v);
    double b = x.Dot(v);
    double discr = b * b - a * c;

    if (discr <= 0)
    {
        return INFINITY;
    }

    double tau = (b - sqrt(discr)) / a;

    if (tau < 0)
    {
        return INFINITY;
    }

    return tau;
}

void CollisionAvoidance::DrawDebug()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::CircleShape circle = sf::CircleShape(radius);
    circle.setOrigin(radius, radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(1);
    circle.setPosition(character->position.x, character->position.y);

    window->draw(circle);
}