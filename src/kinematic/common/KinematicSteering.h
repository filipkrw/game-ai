#ifndef KINEMATICSTEERING_H
#define KINEMATICSTEERING_H

#include "KinematicEntity.h"
#include "KinematicSteeringOutput.h"
#include "../../renderer/Renderer.h"

class KinematicSteering
{
public:
    KinematicSteering(KinematicEntity *character) : character(character)
    {
        steering = KinematicSteeringOutput();
    };

    KinematicEntity *character;
    KinematicSteeringOutput steering;

    void DrawDebug()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(character->position.x, character->position.y), sf::Color::White),
            sf::Vertex(sf::Vector2f(character->position.x + steering.velocity.x, character->position.y + steering.velocity.y), sf::Color::White)};

        window->draw(line, 2, sf::Lines);
    }
};

#endif // KINEMATICSTEERING_H
