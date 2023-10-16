#include "Seek.h"
#include "../../core/renderer/Renderer.h"

SteeringOutput Seek::GetSteering(Vector2 target)
{
    SteeringOutput steering = SteeringOutput();

    steering.velocity = Vector2::Normalize(target - character->position) * maxSpeed;
    steering.rotation = LookAhead::GetSteering().rotation;

    return steering;
};

void Seek::DrawDebug()
{
    // sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    // sf::Vertex line[] = {
    //     sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
    //     sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

    // window->draw(line, 2, sf::Lines);
}