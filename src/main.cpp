#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "renderer/Renderer.h"
#include "crosshair/Crosshair.h"

int main()
{
    Crosshair crosshair = Crosshair();

    GameWorld gameWorld = GameWorld();

    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Clock deltaClock;

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color::Red);

    while (window->isOpen())
    {
        double dt = deltaClock.restart().asSeconds();
        sf::Event event;

        while (window->pollEvent(event))
        {
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

        gameWorld.Update(dt);
        crosshair.Update(dt);

        window->clear(sf::Color::Black);
        gameWorld.Render();
        crosshair.Render();

        window->display();
    }

    return 0;
}