#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <cmath>
#include <vector>
#include "shapes/circle.hpp"
#include <iostream>
using namespace std;

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){
    double distance =0;
    distance =sqrt(pow(C.x-A.x,2)+pow(C.y-A.y,2));
    return distance/sqrt(2);
}

double Square::perimeter(){
    return side()*4;
}
    
double Square::area(){
    return pow(side(),2);
}

Point Square::center(){
    Point M;
    M.x=(A.x+C.x)/2;
    M.y=(A.y+C.y)/2;
    return M;
}

void Square::draw(){
    Point B,D,M;
    M =center();
    B.x=M.x-(A.y-M.y);
    B.y=M.y+(A.x-M.x);
    D.x=M.x+(A.y-M.y);
    D.y=M.y-(A.x-M.x);
    std::vector<Point> po = {A,B,C,D,A};
    draw_picture(po);
}

void Square::translate(Point T){
    Point M;
    M =center();
    double xAM,yAM,xCM,yCM;
    xAM=A.x-M.x;
    yAM=A.y-M.y;
    xCM=C.x-M.x;
    yCM=C.y-M.y;
    M=T;
    A.x=M.x+xAM;
    A.y=M.y+yAM;
    C.x=M.x+xCM;
    C.y=M.y+yCM;
    draw();
}

void Square::resize(double ratio){
    Point M;
    M =center();
    double xAM,yAM,xCM,yCM;
    xAM=(A.x-M.x)*ratio;
    yAM=(A.y-M.y)*ratio;
    xCM=(C.x-M.x)*ratio;
    yCM=(C.y-M.y)*ratio;

    A.x=M.x+xAM;
    A.y=M.y+yAM;
    C.x=M.x+xCM;
    C.y=M.y+yCM;
    draw();
}
void Square::rotate(double angle) {
    
    Point M = center();

    double rad = angle * 3.14 / 180.0; //c'est pour convertir angle en radians

    double ax = A.x - M.x;
    double ay = A.y - M.y;
    A.x = M.x + ax * cos(rad) - ay * sin(rad);
    A.y = M.y + ax * sin(rad) + ay * cos(rad);

    double cx = C.x - M.x;
    double cy = C.y - M.y;
    C.x = M.x + cx * cos(rad) - cy * sin(rad);
    C.y = M.y + cx * sin(rad) + cy * cos(rad);

    draw(); 
}


bool Square::equals(Square square){
    if(square.side()==side()){
        return true;
    }
    return false;
}
Circle Square::inscribedCircle(){
    Circle c1(side()/2,center());
    return c1;
}

Circle Square::circumscribedCircle(){
    Point M=center();
    double distance =sqrt(pow(M.x-A.x,2)+pow(M.y-A.y,2));
    Circle c2(distance,center());
    return c2;
}

