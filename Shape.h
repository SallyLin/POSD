#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>
#include "Painter.h"
class Rectangle;

class Shape{
public:
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual std::string describe() {return std::string("");}
    virtual Painter* getPainter(){return new Painter(); }
};


#endif // SHAPE_H_INCLUDED
