#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int ll_x, int ll_y, int length, int width);
    int area();
    Rectangle getBoundingBox();
    int llx() const{return rx;}
    int lly() const{return ry;}
    int urx() const{return rx+l;}
    int ury() const{return ry+w;}
    std::string describe();
    Painter* getPainter();
    void changePoint(int del_x, int del_y);
    bool isInArea(int x, int y);

    //int perimeter();
private:
    int rx, ry;
    int l, w;

};


#endif // RECTANGLE_H_INCLUDED
