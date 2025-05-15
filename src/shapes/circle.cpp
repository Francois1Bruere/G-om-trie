#include "draw.hpp"
#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <vector>

using namespace std;

Circle::Circle(double r, Point c) : radius(r), center(c) {}

double Circle::circumference()
{
    return 2 * 3.14 * radius;
}

double Circle::area()
{
    return 3.14 * radius * radius;
}

void Circle::draw()
{
    vector<Point> points;
    int num_points = 250;

    for (int i = 0; i < num_points; i++)
    {
        double angle = (2 * 3.14 * i) / num_points;
        double x = radius * cos(angle) + center.x;
        double y = radius * sin(angle) + center.y;

        points.push_back(Point(x, y));
    }

    draw_picture(points);
}

void Circle::translate(Point T)
{
    center.x += T.x;
    center.y += T.y;
    draw();
}

void Circle::resize(double ratio)
{
    radius *= ratio;
    draw();
}
// les trois figures sont presentent
bool Circle::equals(Circle circle) // deux cercles sont egaux quand ils ont le meme centre meme rayon
{
    return (center.x == circle.center.x && center.y == circle.center.y && radius == circle.radius);
}
