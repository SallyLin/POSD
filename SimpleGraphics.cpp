#include "SimpleGraphics.h"
#include "Rectangle.h"
#include "AreaVisitor.h"

SimpleGraphics::SimpleGraphics (Shape *shape_inst):s(shape_inst) {}
Rectangle SimpleGraphics::getBoundingBox() {return s->getBoundingBox();}
void SimpleGraphics::accept(GraphicsVisitor &av) {av.visitSimpleGraphics(this);}
Shape * SimpleGraphics::shape() {return s;}
Painter* SimpleGraphics::getPainter(){
    return s->getPainter();
}

std::string SimpleGraphics::description(){
    return s->describe();
}

void SimpleGraphics::changePoint(int del_x, int del_y){
    s->changePoint(del_x, del_y);
}

bool SimpleGraphics::isInArea(int x, int y){
    return s->isInArea(x, y);
}
