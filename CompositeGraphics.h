#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include <vector>
#include "GraphicsVisitor.h"

class CompositeGraphics : public Graphics {
public:
    CompositeGraphics();
    void add (Graphics *g);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor & av);
    Painter* getPainter();
    std::string description();
    vector<Graphics*> getChildren();
    void changePoint(int del_x, int del_y);
    bool isInArea(int x, int y);
    void setChildren(vector<Graphics*> children);
private:
    std::vector<Graphics *> g_obj;
};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
