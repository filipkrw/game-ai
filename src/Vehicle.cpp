#include <iostream>
#include "Vehicle.h"
#include "renderer/Renderer.h"

Vehicle::Vehicle(
    GameWorld *world,
    Vector2 position,
    double rotation,
    Vector2 velocity,
    double mass,
    double maxSpeed,
    double maxForce,
    double maxTurnRate,
    Vector2 scale) : MovingEntity(0, position, rotation, velocity, mass, maxSpeed, maxForce, maxTurnRate, scale)
{
    m_pWorld = world;
    m_pSteering = new SteeringBehaviors(this);
}

void Vehicle::Update(double dt)
{
    // Vector2 steeringForce = m_pSteering->Arrive(Vector2(600, 200), Deceleration::normal);
    Vector2 steeringForce = m_pSteering->Calculate();

    Vector2 acceleration = steeringForce / m_dMass;

    m_vVelocity = m_vVelocity + acceleration * dt;

    m_vVelocity.Truncate(m_dMaxSpeed);

    m_vPosition = m_vPosition + m_vVelocity * dt;

    if (m_vVelocity.LengthSq() > 0.00000001)
    {
        m_vHeading = Vector2::Normalize(m_vVelocity);
        m_vSide = m_vHeading.Perp();
    }
}

void Vehicle::Render()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

    sf::CircleShape circle(10.f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(m_vPosition.X(), m_vPosition.Y());

    window->draw(circle);
}