#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>

int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
	};

	Point A=(0,0), B=(100,0), C=(0,100);
	double r=100;
	Circle F1=Circle(r,A);
	Triangle F2=Triangle(A,B,C);
	F1.draw();
	F2.draw();


	// Draw the picture by connecting the points
	draw_picture(points);
	
	return 0;
}
