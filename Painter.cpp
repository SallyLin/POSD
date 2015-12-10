#include "Painter.h"
#include "Presentation.h"
#include "MainWindow.h"
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

void Painter::setWindow(MainWindow* mainwindow){
    this->mw = mainwindow;
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
    QGraphicsItem::mousePressEvent(event);
    prePoint = pos();
    mw->setSelectedGraphic(description());
}

void Painter::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    QGraphicsItem::mouseMoveEvent(event);
    pen.setColor("red");
    update();
    mw->setDrag(true);
}

void Painter::mouseReleaseEvent(QGraphicsSceneMouseEvent* event){
    event->setAccepted(true);
    QPointF curPoint = pos();
    QPointF delPoint = curPoint - prePoint;
    int del_x = static_cast<int>(delPoint.x());
    int del_y = static_cast<int>(delPoint.y());
    mw->graphicPointChange(del_x, del_y);
}

void Painter::setPos(qreal x, qreal y){
    QGraphicsItem::setPos(x, y);
}

void Painter::selected(){
    pen.setColor("red");
    update();
}
