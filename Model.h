#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "CommandManager.h"
#include "Graphics.h"
#include <string>
#include <iostream>
#include <QPainter>
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

    //used by command
    void addGraphices(Graphics* g);
    void deleteLastGraphics();
private:
    //Graphics* graphics;
    vector<Graphics*> graphics;
    CommandManager cmdMgr;
    int x, y;
};

#endif // MODEL_H_INCLUDED
