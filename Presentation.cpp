#include "Presentation.h"

Presentation::Presentation(Model* model):m(model){ isDrag=false; }

string Presentation::getAllDescription(){
    return m->getAllDescription();
}

vector<Painter*> Presentation::getShapes(){
    return m->getShapes();
}

void Presentation::loadFile(string filename){
    m->loadFile(filename);
}

void Presentation::createCircle(){
    m->actCreateCircle();
}

void Presentation::createRectangle(){
    m->actCreateRectangle();
}

void Presentation::createSquare(){
    m->actCreateSquare();
}

void Presentation::redo(){
    m->actRedo();
}

void Presentation::undo(){
    m->actUndo();
}

void Presentation::group(vector<string> descriptions){
    m->actGroup(descriptions);
}

Painter* Presentation::getNewGroup(){
    return m->getNewGroup();
}
/*
void Presentation::ungroup(string description){
    m->actUngroup(description);
}*/
void Presentation::ungroup(){
    m->actUngroup();
}
/*
void Presentation::omit(string description){
    m->actOmit(description);
}*/

void Presentation::omit(){
    m->actOmit();
}

void Presentation::graphicPointChange(int del_x, int del_y){
    if(isDrag){
        m->actMove(del_x, del_y);
        isDrag = false;
    }
}

void Presentation::setDrag(bool flag){
    this->isDrag = flag;
}

void Presentation::setSelectedGraphicDescription(string description){
    m->setSelectedGraphicDescription(description);
}
