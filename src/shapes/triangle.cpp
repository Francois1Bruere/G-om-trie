#include <cmath>
#include "point.hpp"
#include "draw.hpp"
//#include "triangle.hpp"
#include "../include/shapes/triangle.hpp"
#include <vector>

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

Point Triangle::center() {// computes the center of gravity of the triangle
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

	// rotate counterclockwise around the center of the triangle 
	//use radiants angle

void Triangle::rotate(double angle) {
	// rotate counterclockwise around the center of the triangle 
	//use degree angle
	
    Point o = center();
    double r = angle * M_PI / 180.0;

    A = Point(
        o.x + (A.x - o.x) * cos(r) - (A.y - o.y) * sin(r),
        o.y + (A.x - o.x) * sin(r) + (A.y - o.y) * cos(r)
    );

    B = Point(
        o.x + (B.x - o.x) * cos(r) - (B.y - o.y) * sin(r),
        o.y + (B.x - o.x) * sin(r) + (B.y - o.y) * cos(r)
    );

    C = Point(
        o.x + (C.x - o.x) * cos(r) - (C.y - o.y) * sin(r),
        o.y + (C.x - o.x) * sin(r) + (C.y - o.y) * cos(r)
    );

    draw();
}



bool Triangle::equals(Triangle triangle){
	//memes coord de points
	if(triangle.A.x==A.x and triangle.A.y==A.y and triangle.B.x==B.x and triangle.B.y==B.y and triangle.C.x==C.x and triangle.C.y==C.y){
		return true;
	}
	else{return false;}
}

bool Triangle::isRightAngled() {
    double ab = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
    double bc = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double ca = sqrt((C.x - A.x)*(C.x - A.x) + (C.y - A.y)*(C.y - A.y));

    double eps = 1e-6;

    bool check1 = (ab*ab - (bc*bc + ca*ca) < eps) && ((bc*bc + ca*ca) - ab*ab < eps);
    bool check2 = (bc*bc - (ab*ab + ca*ca) < eps) && ((ab*ab + ca*ca) - bc*bc < eps);
    bool check3 = (ca*ca - (ab*ab + bc*bc) < eps) && ((ab*ab + bc*bc) - ca*ca < eps);

    return check1 || check2 || check3;
}

bool Triangle::isEquilateral() {
    double ab = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
    double bc = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double ca = sqrt((C.x - A.x)*(C.x - A.x) + (C.y - A.y)*(C.y - A.y));

    double eps = 1e-6;

    bool ab_bc = (ab - bc < eps) && (bc - ab < eps);
    bool bc_ca = (bc - ca < eps) && (ca - bc < eps);

    return ab_bc && bc_ca;
}

bool Triangle::isIsoceles() {
    double ab = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
    double bc = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double ca = sqrt((C.x - A.x)*(C.x - A.x) + (C.y - A.y)*(C.y - A.y));

    double eps = 1e-6;

    bool ab_bc = (ab - bc < eps) && (bc - ab < eps);
    bool bc_ca = (bc - ca < eps) && (ca - bc < eps);
    bool ab_ca = (ab - ca < eps) && (ca - ab < eps);

    return ab_bc || bc_ca || ab_ca;
}

Circle Triangle::inscribedCircle() {
    double ab = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
    double bc = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double ca = sqrt((C.x - A.x)*(C.x - A.x) + (C.y - A.y)*(C.y - A.y));

    double p = perimeter();

    double x = (bc * A.x + ca * B.x + ab * C.x) / p;
    double y = (bc * A.y + ca * B.y + ab * C.y) / p;

    double r = area() / (p / 2);

    return Circle(r, Point(x, y));
}

	
Circle Triangle::circumscribedCircle() {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    
    double x = ((A.x*A.x + A.y*A.y)*(B.y - C.y) + 
                (B.x*B.x + B.y*B.y)*(C.y - A.y) + 
                (C.x*C.x + C.y*C.y)*(A.y - B.y)) / D;

    double y = ((A.x*A.x + A.y*A.y)*(C.x - B.x) + 
                (B.x*B.x + B.y*B.y)*(A.x - C.x) + 
                (C.x*C.x + C.y*C.y)*(B.x - A.x)) / D;

    double r = sqrt((x - A.x)*(x - A.x) + (y - A.y)*(y - A.y));

    return Circle(r, Point(x, y));
}
