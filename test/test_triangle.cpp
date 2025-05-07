#include "triangle.hpp"
#include "point.hpp"
#include <cassert>
#include <cmath>
using namespace std;

// Function isequal
bool isEqual(double a, double b, double epsilon = 1e-7) {
    return abs(a - b) < epsilon;
}

void testTriangle() {
    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 4);
    Triangle triangle(A, B, C);

    // Test perimeter
    assert(isequal(triangle.perimeter(), 12.0));

    // Test area
    assert(isequal(triangle.area(), 6.0));

    // Test center
    Point center = triangle.center();
    assert(isequal(center.x, 1.0));
    assert(isequal(center.y, 4.0 / 3.0));

    // Test isRightAngled
    assert(triangle.isRightAngled());

    // Test isEquilateral
    assert(!triangle.isEquilateral());

    // Test isIsoceles
    assert(triangle.isIsoceles());

    // Test inscribedCircle
    Circle inscribed = triangle.inscribedCircle();
    assert(isequal(inscribed.radius, 1.0));
    assert(isequal(inscribed.center.x, 1.0));
    assert(isequal(inscribed.center.y, 1.0));

    // Test circumscribedCircle
    Circle circumscribed = triangle.circumscribedCircle();
    assert(isequal(circumscribed.radius, 2.5));
    assert(isequal(circumscribed.center.x, 1.5));
    assert(isequal(circumscribed.center.y, 2.0));

    // Test translate
    triangle.translate(Point(1, 1));
    Point newCenter = triangle.center();
    assert(isequal(newCenter.x, 2.0));
    assert(isequal(newCenter.y, 7.0 / 3.0));

    // Test resize
    triangle.resize(2.0);
    Point resizedCenter = triangle.center();
    assert(isequal(resizedCenter.x, 2.0));
    assert(isequal(resizedCenter.y, 7.0 / 3.0));

    // Test rotate
    triangle.rotate(M_PI / 2); // Rotate 90 degrees
    Point rotatedCenter = triangle.center();
    assert(isequal(rotatedCenter.x, 2.0));
    assert(isequal(rotatedCenter.y, 7.0 / 3.0));

    // Test equals
    Triangle triangle2(A, B, C);
    assert(triangle.equals(triangle2));
}

int main() {
    testTriangle();
    return 0;
}