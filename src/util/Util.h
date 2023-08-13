#include "Vector2.h"
#include <cmath>
#include <random>

class Util
{
public:
    static double RandomBetween(double min, double max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }

    static Vector2 RandomPointOnCircle(double radius)
    {
        // Get a random angle between 0 and 2π
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 2 * M_PI);

        double angle = dis(gen);
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        return Vector2(x, y);
    }

    static Vector2 PointToWorldSpace(Vector2 targetLocal, Vector2 heading, Vector2 side, Vector2 pos)
    {
        Vector2 result = Vector2(
            targetLocal.X() * heading.X() + targetLocal.Y() * side.X() + pos.X(),
            targetLocal.X() * heading.Y() + targetLocal.Y() * side.Y() + pos.Y());
        return result;
    }
};
