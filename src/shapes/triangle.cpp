#include <cmath>
#include "point.hpp"
#include "triangle.hpp"

using namespace std;

double Triangle::perimeter() {
    double ab = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    double bc = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    double ca = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
    return ab + bc + ca;
}

double Triangle::area() {
    return 0.5 * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

Point Triangle::center() {
    double centerX = (A.x + B.x + C.x) / 3.0;
    double centerY = (A.y + B.y + C.y) / 3.0;
    return Point(centerX, centerY);
}

void Triangle::draw(){
	//from the  main

	// Define points in a vector
	std::vector<Point> points = {
		Point(A.x, A.y),
		Point(B.x, B.y),
		Point(C.x, C.y),
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
}

void Triangle::translate(Point T) {
    Point o = center();
    double dx = T.x - o.x;
    double dy = T.y - o.y;
    
    A.x += dx; 
    A.y += dy;
    
    B.x += dx; 
    B.y += dy;
    
    C.x += dx; 
    C.y += dy;
}

void Triangle::resize(double ratio) {
    Point o = center();

    A.x = o.x + (A.x - o.x) * ratio;
    A.y = o.y + (A.y - o.y) * ratio;
    
    B.x = o.x + (B.x - o.x) * ratio;
    B.y = o.y + (B.y - o.y) * ratio;
    
    C.x = o.x + (C.x - o.x) * ratio;
    C.y = o.y + (C.y - o.y) * ratio;

}

void Triangle::rotate(double angle) {
	// rotate counterclockwise around the center of the triangle 
	//use radiants angle
	
}


bool equals(Triangle triangle){
	if(triangle.A.x==A.x and triangle.A.y==A.y and triangle.B.x==B.x and triangle.B.y==B.y and triangle.C.x==C.x and triangle.C.y==C.y){
		return true;
	}
	else{return false;}
}

bool isRightAngled(){}

bool isEquilateral(){}

bool isIsoceles(){}
