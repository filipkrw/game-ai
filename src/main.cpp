#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "renderer/Renderer.h"
#include "crosshair/Crosshair.h"
#include "demos/ArriveDemo.h"
#include "demos/Demo.h"

int main()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Clock deltaClock;

    ArriveDemo arriveDemo = ArriveDemo();

    while (window->isOpen())
    {
        double dt = deltaClock.restart().asSeconds();
        sf::Event event;

        while (window->pollEvent(event))
        {
            arriveDemo.ProcessEvent(event);

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

        arriveDemo.Update(dt);

        window->clear(sf::Color::Black);
        arriveDemo.Render();
        window->display();
    }

    return 0;
}