#ifndef SHAPEVISITOR_H_INCLUDED
#define SHAPEVISITOR_H_INCLUDED

#include "GraphicsVisitor.h"

#include "Painter.h"
#include <vector>
#include <stack>

using namespace std;

class ShapeVisitor : public GraphicsVisitor{
public:
    ShapeVisitor();
    ~ShapeVisitor();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics(CompositeGraphics *cg);
    vector<Painter*> getPainters();
    void pushChildNum(int num);
    void compose();
private:
    vector<Painter*> painters;
    stack<int> groupChildNum;
};

#endif // SHAPEVISITOR_H_INCLUDED
