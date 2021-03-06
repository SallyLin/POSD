#include "CompositeGraphics.h"
#include <algorithm>
#include "Rectangle.h"
#include "GraphicsVisitor.h"
#include "AreaVisitor.h"

CompositeGraphics::CompositeGraphics(){}
void CompositeGraphics::add(Graphics *g) {g_obj.push_back(g);}
Rectangle CompositeGraphics::getBoundingBox() {
    if (g_obj.size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i!=g_obj.end();++i) {
        minx.push_back((*i)->getBoundingBox().llx());
        miny.push_back((*i)->getBoundingBox().lly());
        maxx.push_back((*i)->getBoundingBox().urx());
        maxy.push_back((*i)->getBoundingBox().ury());
    }
    int llx = *min_element(minx.begin(),minx.end());
    int lly = *min_element(miny.begin(),miny.end());
    int urx = *max_element(maxx.begin(),maxx.end());
    int ury = *max_element(maxy.begin(),maxy.end());

    return Rectangle(llx,lly,urx-llx,ury-lly);
}

void CompositeGraphics::accept(GraphicsVisitor & av) {
    av.visitCompositeGraphics(this);
    av.enter();
    av.pushChildNum(g_obj.size());
    for (auto e:g_obj)
        e->accept(av);
    av.compose();
    av.leave();
}

Painter* CompositeGraphics::getPainter(){
    Rectangle bounding = getBoundingBox();
    Painter* p = bounding.getPainter();
    std::string d("Comp ");
    d += bounding.describe();
    p->setDescription(d);
    p->green();
    return p;
}

std::string CompositeGraphics::description(){
    std::string d("Comp ");
    d += getBoundingBox().describe();
    return d;
}

vector<Graphics*> CompositeGraphics::getChildren(){
    return this->g_obj;
}

void CompositeGraphics::changePoint(int del_x, int del_y){
    for(auto g : g_obj){
        g->changePoint(del_x, del_y);
    }
}

bool CompositeGraphics::isInArea(int x, int y){
    return getBoundingBox().isInArea(x, y);
}

void CompositeGraphics::setChildren(vector<Graphics*> children){
    g_obj.clear();
    for(auto child : children){
        g_obj.push_back(child);
    }
    //this->g_obj = children;
}
