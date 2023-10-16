#include "Wander.h"
#include "../../util/Util.h"
#include "../../core/renderer/Renderer.h"

SteeringOutput Wander::GetSteering()
{
    wanderOrientation += Util::RandomBetween(-1, 1) * wanderRate;

    double targetOrientation = wanderOrientation + character->orientation;

    target = character->position + (Vector2::FromAngle(character->orientation) * wanderOffset);
    target += Vector2::FromAngle(targetOrientation) * wanderRadius;

    SteeringOutput steering = Face::GetSteering(target);

    steering.velocity = Vector2::FromAngle(character->orientation) * maxAcceleration;

    return steering;
}

void Wander::DrawDebug()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    // draw wander circle
    sf::CircleShape circle(wanderRadius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1.0f);
    circle.setOutlineColor(sf::Color::Green);
    Vector2 circleCenter = character->position + (Vector2::FromAngle(character->orientation) * wanderOffset);
    circle.setPosition(circleCenter.x - wanderRadius, circleCenter.y - wanderRadius); // Assuming the origin of the circle is at the center
    window->draw(circle);

    // draw wander target
    sf::CircleShape targetCircle(5);
    targetCircle.setFillColor(sf::Color::Green);
    targetCircle.setPosition(target.x - 5, target.y - 5);
    window->draw(targetCircle);
}
