#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"
#include <QPainter>
#include "Painter.h"
class Circle : public Shape {
public:
    Circle(int center_x, int center_y, int radius);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    Painter* getPainter();
    void changePoint(int del_x, int del_y);
    bool isInArea(int x, int y);
    //int perimeter();
private:
    int cx, cy;
    int r;
};

#endif // CIRCLE_H_INCLUDED
