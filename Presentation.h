#ifndef PRESENTATION_H_INCLUDED
#define PRESENTATION_H_INCLUDED

#include "Model.h"
#include <vector>
#include <string>
#include "Painter.h"

class Presentation{
public:
    Presentation(Model* model);
    string getAllDescription();
    vector<Painter*> getShapes();
    void loadFile(string fileName);
    void createSquare();
    void createCircle();
    void createRectangle();
    void undo();
    void redo();
    //void omit(string descriptoin);
    void omit();
    void group(vector<string> descriptoins);
    //void ungroup(string description);
    void ungroup();
    Painter* getNewGroup();
    void graphicPointChange(int del_x, int del_y);
    void setDrag(bool flag);
    void setSelectedGraphicDescription(string description);
private:
    Model* m;
    string curGraphicDescription;
    bool isDrag;
};

#endif // PRESENTATION_H_INCLUDED
