#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Shape.h"

class Square : public Shape {
public:
    Square(int ll_x, int ll_y, int length);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    Painter* getPainter();
    void changePoint(int del_x, int del_y);
    bool isInArea(int x, int y);
private:
    int sx, sy;
    int l;

};


#endif // SQUARE_H_INCLUDED
