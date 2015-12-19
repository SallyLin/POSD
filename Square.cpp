#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>
#include "SquarePainter.h"
Square::Square(int ll_x, int ll_y, int length)
    :sx(ll_x),sy(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(sx,sy,l,l);}
std::string Square::describe() {
    std::ostringstream oss;
    oss << "S(" << sx <<"," << sy << "," << l <<")";
    return oss.str();
}

Painter* Square::getPainter(){
    qreal rx(sx), ry(sy), length(l);
    SquarePainter* sp = new SquarePainter(rx, ry, length, describe());
    return sp;
}

void Square::changePoint(int del_x, int del_y){
    sx += del_x;
    sy += del_y;
}

bool Square::isInArea(int x, int y){
    if((x <= sx+l && x >= sx) && (y <= sy+l && y >= sy))
        return true;
    return false;
}

