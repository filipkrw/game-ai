#ifndef VECTOR2_H
#define VECTOR2_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

class Vector2
{
public:
    double x;
    double y;

public:
    Vector2()
    {
        x = 0;
        y = 0;
    }

    Vector2(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double X() { return x; }
    double Y() { return y; }

    double Length() { return sqrt(x * x + y * y); }
    Vector2 Perp() { return Vector2(-y, x); }

    static Vector2 Normalize(Vector2 vector)
    {
        if (vector.Length() == 0)
        {
            return Vector2(0, 0);
        }
        return Vector2(vector.x / vector.Length(), vector.y / vector.Length());
    }

    void Truncate(double max)
    {
        if (this->LengthSq() > max * max)
        {
            this->Normalize();
            this->x *= max;
            this->y *= max;
        }
    }

    void Normalize()
    {
        float length = this->Length();
        if (length == 0)
        {
            return;
        }
        this->x = this->x / length;
        this->y = this->y / length;
    }

    double LengthSq() { return x * x + y * y; }

    Vector2 operator+(Vector2 vector)
    {
        return Vector2(this->x + vector.x, this->y + vector.y);
    }

    Vector2 operator-(Vector2 vector)
    {
        return Vector2(this->x - vector.x, this->y - vector.y);
    }

    Vector2 operator*(double scalar)
    {
        return Vector2(this->x * scalar, this->y * scalar);
    }

    Vector2 operator/(double scalar)
    {
        return Vector2(this->x / scalar, this->y / scalar);
    }

    Vector2 operator+=(Vector2 vector)
    {
        this->x += vector.x;
        this->y += vector.y;
        return *this;
    }

    Vector2 operator*=(double scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2 operator/=(double scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    Vector2 operator-=(Vector2 vector)
    {
        this->x -= vector.x;
        this->y -= vector.y;
        return *this;
    }

    // reverse velocity
    Vector2 operator-()
    {
        return Vector2(-this->x, -this->y);
    }

    static Vector2 FromAngle(double angle)
    {
        return Vector2(-sin(angle), cos(angle));
    }

    double DistanceSq(Vector2 vector)
    {
        double ySeparation = vector.y - this->y;
        double xSeparation = vector.x - this->x;

        return ySeparation * ySeparation + xSeparation * xSeparation;
    }

    double Dot(Vector2 vector)
    {
        return this->x * vector.x + this->y * vector.y;
    }

    void Zero()
    {
        x = 0;
        y = 0;
    }

    static Vector2 WrapAround(Vector2 pos, int maxX, int maxY)
    {
        if (pos.X() > maxX)
        {
            pos.x = 0.0;
        }

        if (pos.X() < 0)
        {
            pos.x = (double)maxX;
        }

        if (pos.Y() < 0)
        {
            pos.y = (double)maxY;
        }

        if (pos.Y() > maxY)
        {
            pos.y = 0.0;
        }

        return pos;
    }
};

#endif // VECTOR2_H