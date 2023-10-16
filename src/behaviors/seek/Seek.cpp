#include "Seek.h"
#include "../../core/renderer/Renderer.h"

void Seek::GetSteering(Vector2 target)
{
    steering.velocity = Vector2::Normalize(target - character->position) * maxSpeed;

    // character.orientation = atan2(steering.velocity.x, steering.velocity.y);

    steering.rotation = 0;
};

void Seek::DrawDebug()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
        sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

    window->draw(line, 2, sf::Lines);
}