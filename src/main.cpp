#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"
#include "core/renderer/Renderer.h"
#include "crosshair/Crosshair.h"
#include "behaviors/seek/SeekDemo.h"
#include "behaviors/arrive/ArriveDemo.h"
#include "behaviors/align/AlignDemo.h"
#include "behaviors/face/FaceDemo.h"

int main()
{
    sf::RenderWindow *window = Renderer::getInstance()->GetWindow();
    sf::Clock deltaClock;

    // ArriveDemo demo = ArriveDemo();
    // SeekDemo demo = SeekDemo();

    // SeekDemo demo = SeekDemo();
    ArriveDemo demo = ArriveDemo();
    // AlignDemo demo = AlignDemo();
    // FaceDemo demo = FaceDemo();

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