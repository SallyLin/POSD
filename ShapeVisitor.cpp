#include "ShapeVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
ShapeVisitor::~ShapeVisitor(){}

void ShapeVisitor::visitCompositeGraphics(CompositeGraphics *cg){
    painters.push_back(cg->getPainter());
}

void ShapeVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    painters.push_back(sg->getPainter());
}

vector<Painter*> ShapeVisitor::getPainters(){
    return painters;
}
