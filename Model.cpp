#include "Model.h"
#include "GraphicsFactory.h"
#include "Graphics.h"
#include "DescriptionVisitor.h"
#include "ShapeVisitor.h"
#include "CreateSquareCommand.h"
#include "CreateCircleCommand.h"
#include "CreateRectangleCommand.h"
Model::Model(){
    x=-100;
    y=-100;
}
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

void Model::actCreateSquare(){
    cmdMgr.execute(new CreateSqaureCommand(this, x, y, 100));
    x+=100;
}

void Model::actCreateCircle(){
    cmdMgr.execute(new CreateCircleCommand(this, x, y, 50));
    x+=50;
    y+=50;
}

void Model::actCreateRectangle(){
    cmdMgr.execute(new CreateRectangleCommand(this, x, y, 200, 100));
    y+=100;
}

void Model::addGraphices(Graphics* g){
    graphics.push_back(g);
}

void Model::deleteLastGraphics(){
    graphics.pop_back();
}

void Model::actUndo(){
    cmdMgr.undo();
}

void Model::actRedo(){
    cmdMgr.redo();
}
