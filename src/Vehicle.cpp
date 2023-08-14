#include <iostream>
#include "Vehicle.h"
#include "renderer/Renderer.h"

Vehicle::Vehicle(
    GameWorld *world,
    VehicleParams params) : MovingEntity(params.initialPosition, 0, Vector2(0, 1), params.mass, params.maxSpeed, params.maxForce, params.maxTurnRate, params.scale, params.boundingRadius)
{
    m_pWorld = world;
    m_pSteering = new SteeringBehaviors(this);
}

void Vehicle::Update(double dt)
{
    Vector2 steeringForce = m_pSteering->Calculate();
    Vector2 acceleration = steeringForce / m_dMass;

    m_vVelocity += acceleration * dt;
    m_vVelocity.Truncate(m_dMaxSpeed);

    m_vPosition += m_vVelocity * dt;

    if (m_vVelocity.LengthSq() > 0.00000001)
    {
        m_vHeading = Vector2::Normalize(m_vVelocity);
        m_vSide = m_vHeading.Perp();
    }

    m_vPosition = Vector2::WrapAround(m_vPosition, 900, 600);
}

void Vehicle::Render()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(m_vPosition.X() + m_vHeading.X() * 20, m_vPosition.Y() + m_vHeading.Y() * 20));
    triangle.setPoint(1, sf::Vector2f(m_vPosition.X() + m_vSide.X() * 10, m_vPosition.Y() + m_vSide.Y() * 10));
    triangle.setPoint(2, sf::Vector2f(m_vPosition.X() - m_vSide.X() * 10, m_vPosition.Y() - m_vSide.Y() * 10));
    triangle.setFillColor(sf::Color::Transparent);
    triangle.setOutlineColor(sf::Color::Blue);
    triangle.setOutlineThickness(1.f);

    window->draw(triangle);

    if (m_pSteering->isPursuitOn())
    {
        sf::RectangleShape rectangle(sf::Vector2f(8, 8));
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition(m_pSteering->m_vPursuitTarget.X() - 4, m_pSteering->m_vPursuitTarget.Y() - 4);
        window->draw(rectangle);
    }

    // if (m_pSteering->isWanderOn())
    // {
    //     sf::CircleShape circle(m_pSteering->m_dWanderRadius);
    //     circle.setFillColor(sf::Color::Transparent);
    //     circle.setOutlineColor(sf::Color::Red);
    //     circle.setOutlineThickness(1.f);

    //     // darw circle in front of vehicle
    //     circle.setPosition(
    //         m_vPosition.X() + m_vHeading.X() * m_pSteering->m_dWanderDistance - m_pSteering->m_dWanderRadius,
    //         m_vPosition.Y() + m_vHeading.Y() * m_pSteering->m_dWanderDistance - m_pSteering->m_dWanderRadius);

    //     window->draw(circle);

    //     sf::RectangleShape rectangle(sf::Vector2f(8, 8));
    //     rectangle.setFillColor(sf::Color::Green);

    //     Vector2 targetLocal = m_pSteering->m_vWanderTarget + Vector2(m_pSteering->m_dWanderDistance, 0);

    //     Vector2 targetWorld = Util::PointToWorldSpace(
    //         targetLocal,
    //         m_vHeading,
    //         m_vSide,
    //         m_vPosition);

    //     rectangle.setPosition(targetWorld.X() - 4, targetWorld.Y() - 4);

    //     window->draw(rectangle);
    // }
}