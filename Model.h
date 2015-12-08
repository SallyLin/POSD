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
    void actOmit(string description);
    void actGroup(vector<string> descriptions);
    void actUngroup(string description);
    Painter* getNewGroup();

    //used by commands
    void addGraphices(Graphics* g);
    void deleteLastGraphics();
    void groupGraphis(vector<string> descriptions);
    void ungroupGraphics(Graphics* g);
    void executeUngroup(string description);
    void unexecuteUngroup(int childNum);
    void deleteGraphic(int index);
    void recoverGraphic(int index);
private:
    //Graphics* graphics;
    vector<Graphics*> graphics;
    CommandManager cmdMgr;
    int x, y;
    stack<Graphics*> trashcan;
};

#endif // MODEL_H_INCLUDED
