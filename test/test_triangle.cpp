#include "../include/shapes/triangle.hpp"
#include "../include/point.hpp"
#include <cassert>
#include <cmath>
using namespace std;

// Function isequal
bool isequal(double a, double b, double epsilon = 1e-8) {
    return abs(a - b) < epsilon;
}

void testTriangle() {
    Point A(0, 0), B(1, 0), C(0, 1), D(-1, 0);
    Triangle triangle(A, B, C);
	Triangle triangle2(A, A, A);
	Triangle triangle3(A,B,D);

    // Test perimeter
    assert(isequal(triangle.perimeter(), 3.41));
	assert(isequal(triangle2.perimeter(), 0));
	assert(isequal(triangle3.perimeter(), 4));

    // Test area
    assert(isequal(triangle.area(), 0.5));
	assert(isequal(triangle.area(), 0));
	assert(isequal(triangle.area(), 0));

    // Test center
    Point center = triangle.center(), center2 = triangle2.center(), center3 = triangle3.center();
    assert(isequal(center.x, 1/3));
    assert(isequal(center.y, 1/3));
	assert(isequal(center2.x, 0));
	assert(isequal(center2.y, 0));
 	assert(isequal(center3.x, 0));
 	assert(isequal(center3.y, 0));


    // Test isRightAngled
    assert(triangle.isRightAngled());
    assert(!triangle3.isRightAngled());

    // Test isEquilateral
    assert(!triangle.isEquilateral());
	assert(triangle2.isEquilateral());
 	assert(!triangle3.isEquilateral());

    // Test isIsoceles
    assert(triangle.isIsoceles());

    // Test inscribedCircle
    Circle inscribed = triangle.inscribedCircle();
    assert(isequal(inscribed.radius, 0.707));
    assert(isequal(inscribed.center.x, 0.5));
    assert(isequal(inscribed.center.y, 0.5));

    // Test circumscribedCircle
    Circle circumscribed = triangle.circumscribedCircle();
    assert(isequal(circumscribed.radius, 0.2929));
    assert(isequal(circumscribed.center.x, 0.2929));
    assert(isequal(circumscribed.center.y, 0.2929));

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
    triangle.rotate(3.14159/ 2); // Rotate 90 degrees
    Point rotatedCenter = triangle.center();
    assert(isequal(rotatedCenter.x, 2.0));
    assert(isequal(rotatedCenter.y, 7.0 / 3.0));

    // Test equals
    assert(triangle.equals(triangle));
    assert(triangle2.equals(triangle2));
	assert(triangle3.equals(triangle3));
}

int main() {
    testTriangle();
    return 0;
}