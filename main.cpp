#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>

<<<<<<< HEAD
=======

>>>>>>> 09649898c36814cafc288fc18f0c18847106a5a7
int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	
	return 0;
}
