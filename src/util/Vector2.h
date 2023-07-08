#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

class Vector2
{
    sf::Vector2<double> vector;

public:
    Vector2()
    {
        vector.x = 0;
        vector.y = 0;
    }

    Vector2(double x, double y)
    {
        vector.x = x;
        vector.y = y;
    }

    double Length() { return sqrt(vector.x * vector.x + vector.y * vector.y); }
    Vector2 Perp() { return Vector2(-vector.y, vector.x); }

    static Vector2 Normalize(Vector2 vector)
    {
        return Vector2(vector.vector.x / vector.Length(), vector.vector.y / vector.Length());
    }
};