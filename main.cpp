#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"

#include <vector>

int main()
{

	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)

	};
	double r = 50;
	Point c = Point(0, 0);
	double ratio = 2;
	Point T = Point(7, 7);
	Circle cer = Circle(r, c);
	cer.area();
	cer.draw();
	cer.translate(T);
	cer.resize(ratio);
	// les trois figures sont presentent
	//  Draw the picture by connecting the points
	//  draw_picture(points);

	return 0;
}
