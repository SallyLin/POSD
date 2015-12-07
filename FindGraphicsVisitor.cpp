#include "FindGraphicsVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "Rectangle.h"
FindGraphicsVisitor::FindGraphicsVisitor(vector<string> descriptions):vecDes(descriptions){}

FindGraphicsVisitor::~FindGraphicsVisitor(){}

void FindGraphicsVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    for(auto d : vecDes){
        string graphicsDescription = sg->description();
        if(graphicsDescription.compare(d) == 0){
            graphics.push_back(sg);
        }
    }
}

void FindGraphicsVisitor::visitCompositeGraphics(CompositeGraphics *cg){
    for(auto d : vecDes){
        string graphicsDescription = cg->description();
        if(graphicsDescription.compare(d) == 0){
            graphics.push_back(cg);
        }
    }
}

vector<Graphics*> FindGraphicsVisitor::getGraphics(){
    return this->graphics;
}
