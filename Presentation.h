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
private:
    Model* m;
};

#endif // PRESENTATION_H_INCLUDED