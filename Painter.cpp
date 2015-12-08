#include "Painter.h"
#include "MainWindow.h"
Painter::Painter(){
    pen.setColor("blue");
    setFlags(QGraphicsItemGroup::ItemIsSelectable | QGraphicsItemGroup::ItemIsMovable);
}

Painter::~Painter(){}

QRectF Painter::boundingRect() const{
    return QRectF(0,0,0,0);
}

void Painter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){}

void Painter::green(){
    pen.setColor("green");
    update();
}

void Painter::setWindow(MainWindow *window){
    this->w = window;
}

std::string Painter::description(){
    return this->des;
}

void Painter::setDescription(std::string content){
    this->des = content;
}

void Painter::addChild(Painter* child){
    children.push_back(child);
    addToGroup(child);
}

vector<Painter*> Painter::getChildren(){
    return this->children;
}
