#include "Presentation.h"

Presentation::Presentation(Model* model):m(model){ isDrag=false; }

string Presentation::getAllDescription(){
    return m->getAllDescription();
}

vector<Painter*> Presentation::getShapes(){
    vector<Painter*> painters = m->getShapes();
    for(auto p : painters){
        if(m->isSelected(p->description()))
            p->selected();
    }
    return painters;
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
    if(!isDrag)
        m->actGroup(descriptions);
}

Painter* Presentation::getNewGroup(){
    return m->getNewGroup();
}

void Presentation::ungroup(){
    if(!isDrag)
        m->actUngroup();
}

void Presentation::omit(){
    if(!isDrag)
        m->actOmit();
}

bool Presentation::isUndoEnable(){
   return m->isUndoEnable();
}

bool Presentation::isRedoEnable(){
    return m->isRedoEnable();
}

bool Presentation::isGraphicSelected(){
    return m->isGraphicSelected();
}

bool Presentation::isGroup(){
    return m->isGroup();
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

void Presentation::setSelectedGraphic(string description){
    m->setSelectedGraphic(description);
}

void Presentation::clearAll(){
    m->clearAll();
}
