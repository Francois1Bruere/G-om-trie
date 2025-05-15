#include "../include/shapes/circle.hpp"
#include "../include/point.hpp"
#include <cassert>
#include <cmath>
using namespace std;

// Function isequal
bool isequal(double a, double b, double epsilon = 1e-7) {
    return abs(a - b) < epsilon;
}

void testCircle() {
    Point center(0, 0);
    Circle circle(5.0, center);

    // Test circumference
    assert(isequal(circle.circumference(), 2 * M_PI * 5.0));

    // Test area
    assert(isequal(circle.area(), M_PI * 25.0));

    // Test translate
    circle.translate(Point(3, 4));
    Point newCenter = circle.center;
    assert(isequal(newCenter.x, 3.0));
    assert(isequal(newCenter.y, 4.0));

    // Test resize
    circle.resize(2.0);
    assert(isequal(circle.radius, 10.0));

    // Test equals
    Circle circle2(5.0, center);
    assert(circle.equals(circle2));
}

int main() {
    testCircle();
    return 0;
}