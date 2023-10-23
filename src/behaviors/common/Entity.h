#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "SteeringOutput.h"
#include "StaticEntity.h"
#include "../../util/Vector2.h"

class Entity : public StaticEntity
{
public:
    Vector2 velocity;
    double rotation;

    double maxSpeed;

    sf::Color color;

public:
    Entity(Vector2 position, double maxSpeed = 100.0f, sf::Color color = sf::Color::Blue) : StaticEntity(position)
    {
        this->maxSpeed = maxSpeed;
        this->color = color;
    };

    Entity(Vector2 position, Vector2 velocity, double maxSpeed = 100.0f, sf::Color color = sf::Color::Blue)
        : StaticEntity(position)
    {
        this->velocity = velocity;
        this->maxSpeed = maxSpeed;
        this->color = color;
    };

    void Update(SteeringOutput steering, double dt);
    double NewOrientation(double currentOrientation, Vector2 velocity);

    void Render();
    void DrawDebug();
};

#endif // ENTITY_H
