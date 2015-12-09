#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include "Painter.h"
class Rectangle;
class GraphicsVisitor;

class Graphics {
public:
    virtual ~Graphics();
    virtual Rectangle getBoundingBox();
    virtual void add(Graphics *g);
    virtual void accept(GraphicsVisitor & av);
    virtual Painter* getPainter();
    virtual std::string description();
    virtual vector<Graphics*> getChildren();
    virtual void changePoint(int del_x, int del_y);
protected:
    Graphics();
};

#endif // GRAPHICS_H_INCLUDED
