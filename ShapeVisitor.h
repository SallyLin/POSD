#ifndef SHAPEVISITOR_H_INCLUDED
#define SHAPEVISITOR_H_INCLUDED

#include "GraphicsVisitor.h"

#include "Painter.h"
#include <vector>

using namespace std;

class ShapeVisitor : public GraphicsVisitor{
public:
    ~ShapeVisitor();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics(CompositeGraphics *cg);
    vector<Painter*> getPainters();
private:
    vector<Painter*> painters;
};

#endif // SHAPEVISITOR_H_INCLUDED
