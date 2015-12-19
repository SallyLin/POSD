#ifndef SIMPLEGRAPHICS_H_INCLUDED
#define SIMPLEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include "Shape.h"

#include <iostream>

class SimpleGraphics : public Graphics {
public:
    SimpleGraphics (Shape *shape_inst);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor &av);
    Shape * shape();
    Painter* getPainter();
    std::string description();
    void changePoint(int del_x, int del_y);
    bool isInArea(int x, int y);
private:
    Shape * s;
};


#endif // SIMPLEGRAPHICS_H_INCLUDED
