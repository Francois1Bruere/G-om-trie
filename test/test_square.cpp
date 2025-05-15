#include "../include/shapes/square.hpp"
#include "../include/point.hpp"
#include "../include/shapes/circle.hpp"
#include <cassert>
#include <cmath>
using namespace std;

bool isequal(double a, double b, double epsilon = 1e-7) {
    return abs(a - b) < epsilon;
}

void testSquare() {
    Point A(0, 0);
    Point C(2, 2);
    Square square(A, C);

    // Test side
    assert(isequal(square.side(), 2.0));

    // Test perimeter
    assert(isequal(square.perimeter(), 8.0));

    // Test area
    assert(isequal(square.area(), 4.0));

    // Test center
    Point center = square.center();
    assert(isequal(center.x, 1.0));
    assert(isequal(center.y, 1.0));

    // Test translate
    square.translate(Point(1, 1));
    Point newCenter = square.center();
    assert(isequal(newCenter.x, 2.0));
    assert(isequal(newCenter.y, 2.0));

    // Test resize
    square.resize(2.0);
    Point resizedCenter = square.center();
    assert(isequal(resizedCenter.x, 2.0));
    assert(isequal(resizedCenter.y, 2.0));

    // Test rotate
    square.rotate(M_PI / 2); // Rotate 90 degrees
    Point rotatedCenter = square.center();
    assert(isequal(rotatedCenter.x, 2.0));
    assert(isequal(rotatedCenter.y, 2.0));

    // Test inscribedCircle
    Circle inscribed = square.inscribedCircle();
    assert(isequal(inscribed.radius, 1.0));
    assert(isequal(inscribed.center.x, 2.0));
    assert(isequal(inscribed.center.y, 2.0));

    // Test circumscribedCircle
    Circle circumscribed = square.circumscribedCircle();
    assert(isequal(circumscribed.radius, sqrt(2.0)));
    assert(isequal(circumscribed.center.x, 2.0));
    assert(isequal(circumscribed.center.y, 2.0));

    // Test equals
    Square square2(A, C);
    assert(square.equals(square2));
}

int main() {
    testSquare();
    return 0;
}