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

void Model::actOmit(){
    cout << "+" << curGraphicDescription <<endl;
    int index=0;
    for(auto g : graphics){
        if(curGraphicDescription.compare(g->description()) == EQUAL){
            cmdMgr.execute(new DeleteCommand(this, index));
            break;
        }
        index++;
    }
}

void Model::actGroup(vector<string> descriptions){
    cmdMgr.execute(new GroupCommand(this, descriptions));
}
void Model::actUngroup(){
    for(auto g : graphics){
        if(curGraphicDescription.compare(g->description()) == EQUAL){
            cmdMgr.execute(new UngroupCommand(this, curGraphicDescription, g->getChildren().size()));
            break;
        }
    }
}

void Model::actMove(int del_x, int del_y){
    for(auto g : graphics){
        if(curGraphicDescription.compare(g->description()) == EQUAL){
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
        //graphics.push_back(cg);
        if(oldGroup == NULL){
            cout << "NULL" << endl;
            groupTrashcan.push_back(cg);
        }else{
            cout << "Not NULL" <<endl;
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

void Model::graphicMove(Graphics* graphics, int del_x, int del_y){
    graphics->changePoint(del_x, del_y);
    updateDescriptions.push(graphics->description());
}

void Model::setSelectedGraphicDescription(string description){
    this->curGraphicDescription = description;
}

Graphics* Model::findGroupFromTrashcan(string description){
    for(auto g : groupTrashcan){
        if(description.compare(g->description()) == EQUAL){
            return g;
        }
    }
    return 0;
}

void Model::clearAll(){
    cmdMgr.~CommandManager();
    while(!trashcan.empty())
        trashcan.pop();
    groupTrashcan.clear();
    while(!updateDescriptions.empty())
        updateDescriptions.pop();
}
