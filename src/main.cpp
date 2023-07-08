#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "Game AI");
    window.setFramerateLimit(144);

    sf::Clock deltaClock;

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        sf::Event event;

        double speed = (dt.asSeconds() * 100) * 10;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    rectangle.move(0, -1 * speed);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    rectangle.move(0, 1 * speed);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    rectangle.move(-1 * speed, 0);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    rectangle.move(1 * speed, 0);
                }

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

        window.clear(sf::Color::Black);
        window.draw(rectangle);

        window.display();
    }

    return 0;
}