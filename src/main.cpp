#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWorld.h"

int main()
{
    GameWorld gameWorld = GameWorld();

    sf::RenderWindow window(sf::VideoMode(900, 600), "Game AI");
    window.setFramerateLimit(144);

    sf::Clock deltaClock;

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        gameWorld.Update(dt.asSeconds());

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}