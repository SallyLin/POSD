#include "Painter.h"
#include "Presentation.h"
#include <QGraphicsSceneMouseEvent>
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

void Painter::setPresentation(Presentation *presentation){
    this->p = presentation;
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

void Painter::mousePressEvent(QGraphicsSceneMouseEvent* event){
    event->setAccepted(true);
    pre_x = px;
    pre_y = py;
    dragStart = event->pos();
    p->setSelectedGraphicDescription(description());
    //cout << description();
    //std::cout << px << ", " << py << endl;
}

void Painter::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    event->setAccepted(false);
    p->setDrag(true);
    QPointF pNew = event->pos();
    location += (pNew - dragStart);
    this->setPos(location);
}

void Painter::mouseReleaseEvent(QGraphicsSceneMouseEvent* event){
    event->setAccepted(true);
    QPointF delPoint = location - dragStart;
    int del_x = static_cast<int>(delPoint.x());
    int del_y = static_cast<int>(delPoint.y());
    p->graphicPointChange(del_x, del_y);
    //std::cout << delPoint.x() << ", " << delPoint.y() << endl;
    //std::cout << px+delPoint.x() << ", " << py+delPoint.y() << endl;
}
