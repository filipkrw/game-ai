#ifndef PATH_H
#define PATH_H

#include <vector>
#include <cmath>
#include "../seek/Seek.h"
#include "../../core/renderer/Renderer.h"

class Path
{
public:
    Path(){};
    Path(std::vector<Vector2> waypoints) : waypoints(waypoints){};

    std::vector<Vector2> waypoints;

    void AddWaypoint(Vector2 waypoint)
    {
        waypoints.push_back(waypoint);
    }

    int GetParam(Vector2 position)
    {
        double closestDistance = std::numeric_limits<double>::max();
        int closestIndex = 0;

        for (int i = 0; i < waypoints.size(); ++i)
        {
            Vector2 diff = waypoints[i] - position;
            double distance = diff.Length();

            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestIndex = i;
            }
        }

        return closestIndex;
    }

    Vector2 GetPosition(int param)
    {
        int index = static_cast<int>(std::floor(param));
        double fraction = param - index;

        if (index < 0)
        {
            return waypoints.front();
        }
        else if (index >= waypoints.size() - 1)
        {
            return waypoints.back();
        }

        Vector2 start = waypoints[index];
        Vector2 end = waypoints[index + 1];

        return start + (end - start) * fraction;
    }

    void Render()
    {
        sf::RenderWindow *window = Renderer::getInstance()->GetWindow();

        for (int i = 0; i < waypoints.size(); i++)
        {
            Vector2 position = waypoints[i];
            sf::CircleShape circle(5);
            circle.setFillColor(sf::Color(30, 30, 30));
            circle.setPosition(position.x - 5, position.y - 5);
            window->draw(circle);

            if (i > 0)
            {
                Vector2 previousPosition = waypoints[i - 1];
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(position.x, position.y)),
                    sf::Vertex(sf::Vector2f(previousPosition.x, previousPosition.y))};
                line[0].color = sf::Color(30, 30, 30);
                line[1].color = sf::Color(30, 30, 30);
                window->draw(line, 2, sf::Lines);
            }
        }
    }
};

#endif // PATH_H
