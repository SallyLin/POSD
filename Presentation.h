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
    void moveUpperLayer();
    void moveLowerLayer();
    Painter* getNewGroup();
    void graphicPointChange(int del_x, int del_y);
    void setDrag(bool flag);
    //void setSelectedGraphicDescription(string description);
    void setSelectedGraphic(string description);
    void clearAll();
    void clearCmds();
    void setSelectedGraphicByMousePoint(int x, int y);

    //action status check
    bool isUndoEnable();
    bool isRedoEnable();
    bool isGraphicSelected();
    bool isGroup();
private:
    Model* m;
    //string curGraphicDescription;
    bool isDrag;
};

#endif // PRESENTATION_H_INCLUDED
