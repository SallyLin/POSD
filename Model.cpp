#include "Model.h"
#include "GraphicsFactory.h"
#include "Graphics.h"
#include "DescriptionVisitor.h"
#include "ShapeVisitor.h"
#include "CreateSquareCommand.h"
#include "CreateCircleCommand.h"
#include "CreateRectangleCommand.h"
#include "Rectangle.h"
#include "CompositeGraphics.h"
#include "GroupCommand.h"
#include "UngroupCommand.h"
#include "DeleteCommand.h"
#include "MoveCommand.h"

#define NULL 0
#define EQUAL 0

Model::Model(){
    x=0;
    y=0;
    selectedGraphic=NULL;
}
void Model::loadFile(string fileName){
    GraphicsFactory gf;
    graphics = gf.buildGraphicsFromFile(fileName.c_str());
    DescriptionVisitor dv;
    for(auto g : graphics)
        g->accept(dv);
}

string Model::getAllDescription(){
    DescriptionVisitor visitor;
    for(auto g : graphics){
        g->accept(visitor);
    }
    string des = visitor.getDescription();
    return des;
}

vector<Painter*> Model::getShapes(){
    ShapeVisitor visitor;
    for(auto g : graphics){
        g->accept(visitor);
    }
    return visitor.getPainters();
}

void Model::actCreateSquare(){
    cmdMgr.execute(new CreateSqaureCommand(this, x, y, 100));
    x+=10;
}

void Model::actCreateCircle(){
    cmdMgr.execute(new CreateCircleCommand(this, x, y, 50));
    x+=50;
    y+=50;
}

void Model::actCreateRectangle(){
    cmdMgr.execute(new CreateRectangleCommand(this, x, y, 200, 100));
    y+=10;
}

void Model::addGraphices(Graphics* g){
    Graphics* oldGraphic = findGraphicFromTrashcan(g->description());
    if(oldGraphic == NULL){
        graphics.push_back(g);
    }else{
        graphics.push_back(oldGraphic);
    }
}

void Model::deleteLastGraphics(){
    graphicTrashcan.push_back(graphics.back());
    graphics.pop_back();
}

void Model::actUndo(){
    cmdMgr.undo();
    selectedGraphic=NULL;
}

void Model::actRedo(){
    cmdMgr.redo();
    selectedGraphic=NULL;
}

void Model::actOmit(){
    int index=0;
    for(auto g : graphics){
        if(selectedGraphic->description().compare(g->description()) == EQUAL){
            cmdMgr.execute(new DeleteCommand(this, index));
            break;
        }
        index++;
    }
    selectedGraphic=NULL;
}

void Model::actGroup(vector<string> descriptions){
    cmdMgr.execute(new GroupCommand(this, descriptions));
    selectedGraphic=NULL;
}
void Model::actUngroup(){

    cmdMgr.execute(new UngroupCommand(this, selectedGraphic->description(), selectedGraphic->getChildren().size()));
    selectedGraphic=NULL;
}

void Model::actMove(int del_x, int del_y){
    for(auto g : graphics){
        if(selectedGraphic->description().compare(g->description()) == EQUAL){
            cmdMgr.execute(new MoveCommand(this, g, del_x, del_y));
        }
    }
}

void Model::groupGraphis(vector<string> descriptions){
    if(!descriptions.empty()){
        vector<Graphics*> children;
        vector<string>::iterator d_it = descriptions.end()-1;
        vector<Graphics*>::iterator g_it = graphics.end()-1;
        while(g_it >= graphics.begin()){
            while(d_it >= descriptions.begin()){
                if((*d_it).compare((*g_it)->description()) == 0){
                    children.push_back((*g_it));
                    graphics.erase(g_it);
                }
                d_it--;
            }
            d_it = descriptions.end()-1;
            g_it--;
        }
        CompositeGraphics* cg = new CompositeGraphics();
        for(auto child : children){
            cg->add(child);
        }
        Graphics* oldGroup = findGroupFromTrashcan(cg->description());
        if(oldGroup == NULL){
            groupTrashcan.push_back(cg);
        }
        graphics.push_back(oldGroup == NULL ? cg : oldGroup);
    }
}

Painter* Model::getNewGroup(){
    vector<Graphics*>::iterator it=graphics.end()-1;
    cout << graphics.at((graphics.size()-1))->description() << endl;
    ShapeVisitor sv;
    (*it)->accept(sv);
    return sv.getPainters().at(0);
}

void Model::ungroupGraphics(Graphics* g){
    vector<Graphics*> children;
    if(g == NULL){
        children = graphics.back()->getChildren();
        graphics.erase(graphics.end()-1);
    }else{
        children = g->getChildren();
        vector<Graphics*>::iterator it = graphics.begin();
        while(it != graphics.end()){
            if(g->description().compare((*it)->description()) == EQUAL){
                graphics.erase(it);
                break;
            }
            it++;
        }
    }
    vector<Graphics*>::iterator it = children.end()-1;
    while(it >= children.begin()){
        cout << (*it)->description() << endl;
        graphics.push_back(*it);
        it--;
    }
}

void Model::executeUngroup(string description){
    for(auto g : graphics){
        if(description.compare(g->description()) == EQUAL){
            ungroupGraphics(g);
            break;
        }
    }
}

void Model::unexecuteUngroup(int childNum){
    CompositeGraphics* cg = new CompositeGraphics();
    vector<Graphics*>::iterator it = graphics.end()-1;
    while(childNum > 0){
        cg->add((*it));
        graphics.erase(it);
        childNum--;
        it--;
    }
    graphics.push_back(cg);
}

void Model::deleteGraphic(int index){
    Graphics* g = (*(graphics.begin()+index));
    graphics.erase(graphics.begin()+index);
    trashcan.push(g);
}

void Model::recoverGraphic(int index){
    Graphics* g = trashcan.top();
    graphics.insert(graphics.begin()+index, g);
    trashcan.pop();
}

void Model::graphicMove(Graphics* graphic, int del_x, int del_y){
    graphic->changePoint(del_x, del_y);
    updateDescriptions.push(graphic->description());
}

void Model::setSelectedGraphic(string description){
    for(auto g : graphics){
        if(description.compare(g->description()) == EQUAL){
            selectedGraphic = g;
            break;
        }
    }
}

Graphics* Model::findGroupFromTrashcan(string description){
    vector<Graphics*>::iterator it;
    for(auto g : groupTrashcan){
        if(description.compare(g->description()) == EQUAL){
            return g;
        }
    }
    return NULL;
}

Graphics* Model::findGraphicFromTrashcan(string description){
    for(auto g : graphicTrashcan){
        if(description.compare(g->description()) == EQUAL){
            return g;
        }
    }
    return NULL;
}

void Model::clearAll(){
    cmdMgr.~CommandManager();
    while(!trashcan.empty())
        trashcan.pop();
    groupTrashcan.clear();
    while(!updateDescriptions.empty())
        updateDescriptions.pop();
    graphics.clear();
}

bool Model::isUndoEnable(){
    return !cmdMgr.isUndoEmpty();
}

bool Model::isRedoEnable(){
    return !cmdMgr.isRedoEmpty();
}

bool Model::isGraphicSelected(){
    return selectedGraphic != NULL;
}

bool Model::isGroup(){
    if(selectedGraphic == NULL) return false;
    try{
        return !selectedGraphic->getChildren().empty();
    }catch(string e){
        return false;
    }
}

bool Model::isSelected(string descripiton){
    if(selectedGraphic != NULL)
        return descripiton.compare(selectedGraphic->description()) == EQUAL;
    else
        return false;
}
