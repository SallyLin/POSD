#include "Circle.h"
#include "Rectangle.h"
#include <sstream>
#include "CirclePainter.h"
const int PI=3;

Circle::Circle(int center_x, int center_y, int radius)
    :cx(center_x),cy(center_y),r(radius) {}
int Circle::area() {return PI*r*r;}
Rectangle Circle::getBoundingBox() {return Rectangle(cx-r,cy-r,2*r,2*r);}
std::string Circle::describe() {
    std::ostringstream oss;
    oss << "C(" << cx <<"," << cy << "," << r <<")";
    return oss.str();
}

Painter* Circle::getPainter(){
    qreal x(cx), y(cy), radius(r);
    CirclePainter* cp = new CirclePainter(x, y, radius, describe());
    return cp;
}
