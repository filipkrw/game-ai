#include "KinematicSeek.h"
#include "../../renderer/Renderer.h"

void KinematicSeek::GetSteering(Vector2 target)
{
    steering.velocity = Vector2::Normalize(target - character->position) * maxSpeed;

    // character.orientation = atan2(steering.velocity.x, steering.velocity.y);

    steering.rotation = 0;
};

void KinematicSeek::DrawDebug()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::Green),
        sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::Green)};

    window->draw(line, 2, sf::Lines);
}