#include "Presentation.h"

Presentation::Presentation(Model* model):m(model){}

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
    m->getNewGroup();
}

void Presentation::ungroup(string description){
    m->actUngroup(description);
}

void Presentation::omit(string description){
    m->actOmit(description);
}
