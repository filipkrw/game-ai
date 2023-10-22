#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "../../util/Vector2.h"
#include "SteeringOutput.h"

class Entity
{
public:
    Vector2 position;
    double orientation;

    Vector2 velocity;
    double rotation;

    double maxSpeed;

    sf::Color color;

public:
    Entity(Vector2 position, double maxSpeed = 100.0f, sf::Color color = sf::Color::Blue);
    Entity(Vector2 position, Vector2 velocity, double maxSpeed = 100.0f, sf::Color color = sf::Color::Blue) : Entity(position, maxSpeed, color)
    {
        this->velocity = velocity;
    };

    void Update(SteeringOutput steering, double dt);
    double NewOrientation(double currentOrientation, Vector2 velocity);

    void Render();
    void DrawDebug();
};

#endif // ENTITY_H
