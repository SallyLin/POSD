#include "Model.h"
#include "GraphicsFactory.h"
#include "Graphics.h"
#include "DescriptionVisitor.h"
#include "ShapeVisitor.h"

void Model::loadFile(string fileName){
    GraphicsFactory gf;
    graphics = gf.buildGraphicsFromFile(fileName.c_str());
    DescriptionVisitor dv;
    for(int i=0 ; i<graphics.size() ; i++)
        graphics.at(i)->accept(dv);
}

string Model::getAllDescription(){
    DescriptionVisitor visitor;
    for(int i=0 ; i<graphics.size() ; i++)
        graphics.at(i)->accept(visitor);
    string des = visitor.getDescription();
    return des;
}

vector<Painter*> Model::getShapes(){
    ShapeVisitor visitor;
    for(int i=0 ; i<graphics.size() ; i++)
        graphics.at(i)->accept(visitor);
    return visitor.getPainters();

    //return visitor.getPainter();
}
