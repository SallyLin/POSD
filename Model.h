#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "CommandManager.h"
#include "Graphics.h"
#include <string>
#include <iostream>
#include <QPainter>
#include <stack>
using namespace std;
class Model{
public:
    Model();
    //used by Presentation
    string getAllDescription();
    vector<Painter*> getShapes();
    void loadFile(string fileName);
    void actCreateSquare();
    void actCreateCircle();
    void actCreateRectangle();
    void actUndo();
    void actRedo();
    void actOmit();
    void actGroup(vector<string> descriptions);
    void actUngroup();
    void actMove(int del_x, int del_y);
    void graphicMove(Graphics* graphics, int del_x, int del_y);
    Painter* getNewGroup();
    void setSelectedGraphicDescription(string description);
    void clearAll();

    //used by commands
    void addGraphices(Graphics* g);
    void deleteLastGraphics();
    void groupGraphis(vector<string> descriptions);
    void ungroupGraphics(Graphics* g);
    void executeUngroup(string description);
    void unexecuteUngroup(int childNum);
    void deleteGraphic(int index);
    void recoverGraphic(int index);
    void graphicMove(string description, int del_x, int del_y);
private:
    Graphics* findGroupFromTrashcan(string description);
    vector<Graphics*> graphics;
    CommandManager cmdMgr;
    int x, y;
    stack<Graphics*> trashcan;
    stack<string> updateDescriptions;
    string curGraphicDescription;
    vector<Graphics*> groupTrashcan;
};

#endif // MODEL_H_INCLUDED
