#ifndef VECTOR2_H
#define VECTOR2_H

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

    double X() { return vector.x; }
    double Y() { return vector.y; }

    double Length() { return sqrt(vector.x * vector.x + vector.y * vector.y); }
    Vector2 Perp() { return Vector2(-vector.y, vector.x); }

    static Vector2 Normalize(Vector2 vector)
    {
        if (vector.Length() == 0)
        {
            return Vector2(0, 0);
        }
        return Vector2(vector.vector.x / vector.Length(), vector.vector.y / vector.Length());
    }

    void Truncate(double max)
    {
        if (this->Length() > max)
        {
            this->vector = Vector2::Normalize(*this).vector * max;
        }
    }

    void Normalize()
    {
        if (this->Length() == 0)
        {
            return;
        }
        this->vector.x /= this->Length();
        this->vector.y /= this->Length();
    }

    double LengthSq() { return vector.x * vector.x + vector.y * vector.y; }

    Vector2 operator+(Vector2 vector)
    {
        return Vector2(this->vector.x + vector.vector.x, this->vector.y + vector.vector.y);
    }

    Vector2 operator-(Vector2 vector)
    {
        return Vector2(this->vector.x - vector.vector.x, this->vector.y - vector.vector.y);
    }

    Vector2 operator*(double scalar)
    {
        return Vector2(this->vector.x * scalar, this->vector.y * scalar);
    }

    Vector2 operator/(double scalar)
    {
        return Vector2(this->vector.x / scalar, this->vector.y / scalar);
    }

    Vector2 operator+=(Vector2 vector)
    {
        this->vector.x += vector.vector.x;
        this->vector.y += vector.vector.y;
        return *this;
    }

    Vector2 operator*=(double scalar)
    {
        this->vector.x *= scalar;
        this->vector.y *= scalar;
        return *this;
    }

    double DistanceSq(Vector2 vector)
    {
        double ySeparation = vector.vector.y - this->vector.y;
        double xSeparation = vector.vector.x - this->vector.x;

        return ySeparation * ySeparation + xSeparation * xSeparation;
    }

    double Dot(Vector2 vector)
    {
        return this->vector.x * vector.vector.x + this->vector.y * vector.vector.y;
    }

    void Zero()
    {
        vector.x = 0;
        vector.y = 0;
    }

    static Vector2 WrapAround(Vector2 pos, int maxX, int maxY)
    {
        if (pos.X() > maxX)
        {
            pos.vector.x = 0.0;
        }

        if (pos.X() < 0)
        {
            pos.vector.x = (double)maxX;
        }

        if (pos.Y() < 0)
        {
            pos.vector.y = (double)maxY;
        }

        if (pos.Y() > maxY)
        {
            pos.vector.y = 0.0;
        }

        return pos;
    }
};

#endif // VECTOR2_H