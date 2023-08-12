#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "renderer/Renderer.h"
#include "crosshair/Crosshair.h"

int main()
{
    GameWorld gameWorld = GameWorld();

    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Clock deltaClock;

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color::Red);

    while (window->isOpen())
    {
        double dt = deltaClock.restart().asSeconds();
        sf::Event event;

        int eventCount = 0;
        sf::Event events[sf::Event::EventType::Count];

        while (window->pollEvent(event))
        {
            events[eventCount] = event;
            eventCount++;

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
            }

            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        gameWorld.Update(dt, events);

        // clear events array
        for (int i = 0; i < 1; i++)
        {
            events[i] = sf::Event();
        }

        window->clear(sf::Color::Black);
        gameWorld.Render();

        window->display();
    }

    return 0;
}