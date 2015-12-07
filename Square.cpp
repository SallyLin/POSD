#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>
#include "SquarePainter.h"
Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(x,y,l,l);}
std::string Square::describe() {
    std::ostringstream oss;
    oss << "S(" << x <<"," << y << "," << l <<")";
    return oss.str();
}

Painter* Square::getPainter(){
    qreal rx(x), ry(y), length(l);
    SquarePainter* sp = new SquarePainter(rx, ry, length, describe());
    return sp;
}
