#ifndef STEERING_H
#define STEERING_H

#include "Entity.h"
#include "SteeringOutput.h"
#include "../../core/renderer/Renderer.h"

class Steering
{
public:
    Steering(Entity *character) : character(character)
    {
        steering = SteeringOutput();
    };

    Entity *character;
    SteeringOutput steering;

    void DrawDebug()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
            sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

        window->draw(line, 2, sf::Lines);
    }
};

#endif // STEERING_H
