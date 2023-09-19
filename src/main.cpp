#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"
#include "Vehicle.h"
#include "renderer/Renderer.h"
#include "crosshair/Crosshair.h"
#include "demos/ArriveDemo.h"
#include "demos/SeekDemo.h"
#include "demos/Demo.h"
#include "kinematic/seek/KinematicSeekDemo.h"
#include "kinematic/arrive/KinematicArriveDemo.h"
#include "kinematic/align/KinematicAlignDemo.h"

int main()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Clock deltaClock;

    // ArriveDemo demo = ArriveDemo();
    // SeekDemo demo = SeekDemo();

    // KinematicSeekDemo demo = KinematicSeekDemo();
    // KinematicArriveDemo demo = KinematicArriveDemo();
    KinematicAlignDemo demo = KinematicAlignDemo();

    while (window->isOpen())
    {
        double dt = deltaClock.restart().asSeconds();
        sf::Event event;

        while (window->pollEvent(event))
        {
            demo.ProcessEvent(event);

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

        demo.BaseUpdate(dt);
        demo.Update(dt);

        window->clear(sf::Color::Black);
        demo.BaseRender();
        demo.Render();
        window->display();
    }

    return 0;
}