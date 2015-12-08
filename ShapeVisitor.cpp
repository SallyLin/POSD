#include "ShapeVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
using namespace std;
ShapeVisitor::ShapeVisitor(){}

ShapeVisitor::~ShapeVisitor(){}

void ShapeVisitor::visitCompositeGraphics(CompositeGraphics *cg){
    painters.push_back(cg->getPainter());
}

void ShapeVisitor::visitSimpleGraphics(SimpleGraphics *sg){
    painters.push_back(sg->getPainter());
}

vector<Painter*> ShapeVisitor::getPainters(){
    return painters;
}

void ShapeVisitor::pushChildNum(int num){
    groupChildNum.push(num);
}

void ShapeVisitor::compose(){
    if(!groupChildNum.empty()){
        int num = groupChildNum.top();
        groupChildNum.pop();
        vector<Painter*> children;
        for(int i=0 ; i<num ; i++){
            children.push_back(painters.back());
            painters.pop_back();
        }
        Painter* group = painters.back();
        for(auto child : children){
            group->addToGroup(child);
        }
    }
}

