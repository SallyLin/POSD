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
/*
void Painter::setPresentation(Presentation *presentation){
    this->p = presentation;
}*/
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
    //event->setAccepted(true);
    dragStart = event->pos();
    prePoint = pos();
    mw->setSelectedGraphicDescription(description());
    //std::cout << "press " << x() << ", " << y() << endl;
}

void Painter::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    QGraphicsItem::mouseMoveEvent(event);
    //event->setAccepted(false);
    mw->setDrag(true);
    /*event->setAccepted(false);
    p->setDrag(true);
    QPointF pNew = event->pos();
    location += (pNew - dragStart);
    this->setPos(location);*/
}

void Painter::mouseReleaseEvent(QGraphicsSceneMouseEvent* event){
    //QGraphicsItem::mouseReleaseEvent(event);
    event->setAccepted(true);
    QPointF dragEnd = event->pos();
    QPointF curPoint = pos();
    QPointF delPoint = curPoint - prePoint;
    //QPointF delPoint = dragEnd - dragStart;
    int del_x = static_cast<int>(delPoint.x());
    int del_y = static_cast<int>(delPoint.y());
    mw->graphicPointChange(del_x, del_y);
    //std::cout << "release " << x() << ", " << y() << endl;
    //std::cout << delPoint.x() << ", " << delPoint.y() << endl;
    //std::cout << px+delPoint.x() << ", " << py+delPoint.y() << endl;
}

void Painter::setPos(qreal x, qreal y){
    QGraphicsItem::setPos(x, y);
}
