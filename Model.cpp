#include "Model.h"
#include "GraphicsFactory.h"
#include "Graphics.h"
#include "DescriptionVisitor.h"
#include "ShapeVisitor.h"

void Model::loadFile(string fileName){
    GraphicsFactory gf;
    graphics = gf.buildGraphicsFromFile(fileName.c_str());
    DescriptionVisitor dv;
    graphics->accept(dv);
    cout << dv.getDescription();
}

string Model::getAllDescription(){
    DescriptionVisitor visitor;
    graphics->accept(visitor);
    string des = visitor.getDescription();
    return des;
}

vector<Painter*> Model::getShapes(){
    ShapeVisitor visitor;
    graphics->accept(visitor);
    return visitor.getPainters();

    //return visitor.getPainter();
}
