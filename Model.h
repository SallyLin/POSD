#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "Graphics.h"
#include <string>
#include <iostream>
#include <QPainter>
using namespace std;
class Model{
public:
    void loadFile(string fileName);
    string getAllDescription();
    vector<Painter*> getShapes();
private:
    Graphics* graphics;
};

#endif // MODEL_H_INCLUDED
