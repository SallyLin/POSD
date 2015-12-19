#include "Rectangle.h"
#include <sstream>
#include "RectanglePainter.h"

Rectangle::Rectangle(int ll_x, int ll_y, int length, int width)
    :rx(ll_x),ry(ll_y),l(length),w(width) {}
int Rectangle::area() {return l*w;}
Rectangle Rectangle::getBoundingBox() {return Rectangle(rx,ry,l,w);}
std::string Rectangle::describe() {
    std::ostringstream oss;
    oss << "R(" << rx <<"," << ry << "," << l << "," << w << ")";
    return oss.str();
}

Painter* Rectangle::getPainter(){
    qreal x(rx), y(ry), length(l), width(w);
    RectanglePainter* rp = new RectanglePainter(x, y, length, width, describe());
    return rp;
}

void Rectangle::changePoint(int del_x, int del_y){
    rx += del_x;
    ry += del_y;
}

bool Rectangle::isInArea(int x, int y){
    if((x <= rx+l && x >= rx) && (y <= ry+w && y >= ry))
        return true;
    return false;
}
