#include "Rectangle.h"
#include <sstream>
#include "RectanglePainter.h"

Rectangle::Rectangle(int ll_x, int ll_y, int length, int width)
    :x(ll_x),y(ll_y),l(length),w(width) {}
int Rectangle::area() {return l*w;}
Rectangle Rectangle::getBoundingBox() {return Rectangle(x,y,l,w);}
std::string Rectangle::describe() {
    std::ostringstream oss;
    oss << "R(" << x <<"," << y << "," << l << "," << w << ")";
    return oss.str();
}

Painter* Rectangle::getPainter(){
    qreal rx(x), ry(y), length(l), width(w);
    RectanglePainter* rp = new RectanglePainter(rx, ry, length, width);
    return rp;
}
