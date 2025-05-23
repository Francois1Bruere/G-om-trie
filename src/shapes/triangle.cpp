#include <cmath>
#include "../../include/point.hpp"
#include "../../include/draw.hpp"
//#include "triangle.hpp"
#include "../../include/shapes/triangle.hpp"
#include <vector>

using namespace std;

//TO DO
//utiliser la fonction qui fait la distance entre 2 points
//def des fonctions quand on fait des actions redondantes

bool pointEquals(Point p1, Point p2, double eps = 1e-6) {
    return fabs(p1.x - p2.x) < eps && fabs(p1.y - p2.y) < eps;
}

Point rotatePoint(const Point& P, const Point& o, double r) {
	double x_new = o.x + (P.x - o.x) * cos(r) - (P.y - o.y) * sin(r);
	double y_new = o.y + (P.x - o.x) * sin(r) + (P.y - o.y) * cos(r);
	return Point(x_new, y_new);
	}

float pi=3.1415922;

Triangle::Triangle(Point P,Point Q,Point R):A(P),B(Q),C(R){}

double Triangle::perimeter() {
    double ab = A.distance(B);
    double bc = B.distance(C);
    double ca = C.distance(A);
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
    std::vector<Point> points = {A, B, C, A};
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
    double r = angle * pi / 180.0;
    
    A = rotatePoint( A,o,  r);

    B = rotatePoint( B,o,  r);

    C = rotatePoint( C,o,  r);

    //draw();
}



bool Triangle::equals(Triangle triangle) {
    std::vector<Point> thisPoints = {A, B, C};
    std::vector<Point> otherPoints = {triangle.A, triangle.B, triangle.C};

    for (int offset = 0; offset < 3; ++offset) {
        bool match = true;
        for (int i = 0; i < 3; ++i) {
            if (!pointEquals(thisPoints[i], otherPoints[(i + offset) % 3])) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }

    return false;
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
    double ab = A.distance(B);
    double bc = B.distance(C);
    double ca = C.distance(A);

    double eps = 1e-6;

    bool ab_bc = (ab - bc < eps) && (bc - ab < eps);
    bool bc_ca = (bc - ca < eps) && (ca - bc < eps);

    return ab_bc && bc_ca;
}

bool Triangle::isIsoceles() {
    double ab = A.distance(B);
    double bc = B.distance(C);
    double ca = C.distance(A);

    double eps = 1e-6;

    bool ab_bc = (ab - bc < eps) && (bc - ab < eps);
    bool bc_ca = (bc - ca < eps) && (ca - bc < eps);
    bool ab_ca = (ab - ca < eps) && (ca - ab < eps);

    return ab_bc || bc_ca || ab_ca;
}

Circle Triangle::inscribedCircle() {
    double ab = A.distance(B);
    double bc = B.distance(C);
    double ca = C.distance(A);

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
